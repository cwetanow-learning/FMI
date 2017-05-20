/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task
* @compiler VC>
*
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>

#include <string>
#include <vector>

#include <Windows.h>

#include "DynamicQueue.h"
#include "Queue.cpp"
#include "Tree.h"
#include "FilesystemHelper.h"

using namespace std;

CONST string TEMP_FILE = "temp.arc";
CONST string PACK_COMMAND = "-Pack";
CONST string UNPACK_COMMAND = "-Unpack";
CONST string LIST_COMMAND = "-List";

Tree* BuildTree(unsigned int frequencyTable[]) {
	Queue<Tree> queue;
	Tree* tree;

	// create node for every char in the table
	for (int i = 0;i < 256;++i)
	{
		if (frequencyTable[i] > 0)
		{
			tree = new Tree;
			tree->set_freq(frequencyTable[i]);
			tree->set_char(static_cast<unsigned char>(i));
			queue.enqueue(tree);
		}
	}

	Tree* secondTree;
	Tree* thirdTree;

	// build the tree from the nodes
	do
	{
		tree = queue.dequeue();
		if (!queue.empty())
		{
			// get the two lowest frequency trees and combine them into one
			secondTree = queue.dequeue();
			thirdTree = new Tree;
			thirdTree->set_freq(tree->get_freq() + secondTree->get_freq());
			thirdTree->set_left(tree->get_root());
			thirdTree->set_right(secondTree->get_root());
			queue.enqueue(thirdTree);
		}
	} while (!queue.empty()); // Untill all trees are combined into one

	return tree;
}

void Encode(string ifile, string ofile)
{
	cout << "Encoding started" << endl;

	ifstream infile(ifile.c_str(), ios::in | ios::binary);
	if (!infile)
	{
		cerr << ifile << " could not be opened!" << endl;
		return;
	}

	ofstream outfile(ofile.c_str(), ios::out | ios::binary);
	if (!outfile)
	{
		cerr << ofile << " could not be opened!" << endl;
		return;
	}

	cout << "Building huffman tree" << endl;

	//array to hold frequency table for all characters in the file
	unsigned int frequencyTable[256];
	for (int i = 0;i < 256;++i)
	{
		frequencyTable[i] = 0;
	}

	//read the whole file and count the char table frequencies
	char character;
	unsigned char unsignedCharacter;
	while (infile.get(character))
	{
		unsignedCharacter = character;
		++frequencyTable[unsignedCharacter];
	}

	infile.clear(); //clear EOF flag
	infile.seekg(0); //reset get() pointer to beginning

	for (int i = 0;i < 256;++i)
	{
		// output frequency table by dividing 32 bit unsigned int values into 4 bytes
		outfile.put(static_cast<unsigned char>(frequencyTable[i] >> 24));
		outfile.put(static_cast<unsigned char>((frequencyTable[i] >> 16) % 256));
		outfile.put(static_cast<unsigned char>((frequencyTable[i] >> 8) % 256));
		outfile.put(static_cast<unsigned char>(frequencyTable[i] % 256));
	}

	Tree* tree = BuildTree(frequencyTable);

	//find binary strings of all chars in the tree and put into a string table
	string binaryStrings[256];
	unsigned char unsignedChar;
	for (unsigned short index = 0;index < 256;++index)
	{
		binaryStrings[index] = "";
		unsignedChar = static_cast<unsigned char>(index);
		tree->GetBinaryString(tree->get_root(), unsignedChar, "", binaryStrings[index]);
	}

	unsigned int total_chars = tree->get_freq();
	unsigned int passedChars = 0;
	int step = total_chars / 100;
	int percent = 0;

	// put coded characters to the output file
	unsigned char binaryChar;
	while (infile.get(character))
	{
		// user experience, much beautifull
		if (passedChars > percent*step)
		{
			percent++;
			cout << "#";
		}

		passedChars++;

		unsignedCharacter = character;
		//send the binary string to the output file 
		for (unsigned int i = 0;i < binaryStrings[unsignedCharacter].size();++i)
		{
			if (binaryStrings[unsignedCharacter].at(i) == '0')
			{
				binaryChar = 0;
			}

			if (binaryStrings[unsignedCharacter].at(i) == '1')
			{
				binaryChar = 1;
			}

			static int bit_pos = 0; //0 to 7 (left to right) on the byte block
			static unsigned char helperChar = '\0'; //byte block to write

			if (binaryChar < 2) //if not EOF
			{
				if (binaryChar == 1)
				{
					helperChar = helperChar | (binaryChar << (7 - bit_pos)); //add a 1 to the byte
				}
				else
				{
					helperChar = helperChar & static_cast<unsigned char>(255 - (1 << (7 - bit_pos))); //add a 0
				}

				++bit_pos;
				bit_pos %= 8;
				if (bit_pos == 0)
				{
					outfile.put(helperChar);
					helperChar = '\0';
				}
			}
			else
			{
				outfile.put(helperChar);
			}
		}

		total_chars--;
	}
	binaryChar = 2; // send EOF
	static int bit_pos = 0;
	static unsigned char helperChar = '\0';

	if (binaryChar < 2) //if not EOF
	{
		if (binaryChar == 1)
		{
			helperChar = helperChar | (binaryChar << (7 - bit_pos)); //add a 1 to the byte
		}
		else
		{
			helperChar = helperChar & static_cast<unsigned char>(255 - (1 << (7 - bit_pos))); //add a 0
		}

		++bit_pos;
		bit_pos %= 8;
		if (bit_pos == 0)
		{
			outfile.put(helperChar);
			helperChar = '\0';
		}
	}
	else
	{
		outfile.put(helperChar);
	}

	infile.close();
	outfile.close();
	remove(ifile.c_str());

	cout << endl << "Encoding done" << endl;
}

void Decode(string ifile, string ofile)
{
	cout << "Starting decoding of " << ifile << endl;

	ifstream infile(ifile.c_str(), ios::in | ios::binary);
	if (!infile)
	{
		cout << ifile << " could not be opened!" << endl;
		return;
	}

	ofstream outfile(ofile.c_str(), ios::out | ios::binary);
	if (!outfile)
	{
		cout << ofile << " could not be opened!" << endl;
		return;
	}

	unsigned int frequencyTable[256];
	char character;
	unsigned char unsignedCharacter;

	//read frequency table from the input file
	for (int i = 0;i < 256;++i)
	{
		//read 4 bytes and combine them into one 32 bit u. int value
		frequencyTable[i] = 0;
		for (int k = 3;k >= 0;--k)
		{
			infile.get(character);
			unsignedCharacter = character;
			frequencyTable[i] += unsignedCharacter*(1 << (8 * k));
		}
	}

	Tree* tree = BuildTree(frequencyTable);

	//read Huffman strings from the input file
	//find out the chars and write into the outreeut file
	string currentString;
	unsigned char foundCharacter;
	unsigned int total_chars = tree->get_freq();
	cout << "total chars to decode:" << total_chars << endl;

	unsigned int passedChars = 0;
	int step = total_chars / 100;
	int percent = 0;
	while (total_chars > 0)
	{
		// for user experience
		if (passedChars > percent*step)
		{
			percent++;
			cout << "#";
		}

		passedChars++;

		currentString = "";
		do
		{
			static int bitPosition = 0;
			// get next character from file
			static unsigned char nextCharacter = infile.get();

			unsignedCharacter = (nextCharacter >> (7 - bitPosition)) % 2; //get the bit from the byte
			++bitPosition;
			bitPosition %= 8;

			if (bitPosition == 0)
			{
				if (!infile.eof())
				{
					nextCharacter = infile.get();
				}
				else
				{
					unsignedCharacter = 2;
				}
			}

			if (unsignedCharacter == 0)
			{
				currentString = currentString + '0';
			}
			else if (unsignedCharacter == 1)
			{
				currentString = currentString + '1';
			}
		} while (!tree->GetCharacter(currentString, foundCharacter));

		outfile.put(static_cast<char>(foundCharacter));
		--total_chars;
	}

	infile.close();
	outfile.close();

	cout << endl << "Decoding done" << endl;
}

void CompressDirectory(string directory, string outFile) {
	DynamicQueue<string> files;

	// reads the files in the directory
	FilesystemHelper helper;
	helper.TraverseDirectory(directory + "\\", "", files);

	// saves them to one file
	helper.SaveToFile(directory + "\\", files, TEMP_FILE);

	// encodes the combined file
	Encode(TEMP_FILE, outFile);
}

void DecompressDirectory(string file, string outDirectory) {
	// decode the input file
	Decode(file, TEMP_FILE);

	// write the decompressed file to the output directory
	FilesystemHelper helper;
	helper.RestoreDirectory(TEMP_FILE, outDirectory + "\\");
}

void ParseInput(char** input) {
	string command = input[1];

	if (command == PACK_COMMAND)
	{
		string directory = input[2];
		string outFile = input[3];

		CompressDirectory(directory, outFile);
	}
	else if (command == UNPACK_COMMAND)
	{
		string file = input[2];
		string outDirectory = input[3];

		DecompressDirectory(file, outDirectory);
	}
	else if (command == LIST_COMMAND)
	{
		string file = input[2];

		cout << "Not implemented" << endl;
	}
}

int main(int argc, char** argv)
{
	ParseInput(argv);

	return 0;
}

