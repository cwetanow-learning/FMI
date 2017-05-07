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
#include "FilesystemHelper.h"
#include "StringData.h"
#include "Windows.h"

#include <vector>

using namespace std;

FilesystemHelper::FilesystemHelper()
{
}


FilesystemHelper::~FilesystemHelper()
{
}

std::streampos FilesystemHelper::GetFileSize(const char * filePath)
{
	streampos fsize = 0;
	ifstream file(filePath, std::ios::binary);

	fsize = file.tellg();
	file.seekg(0, ios::end);
	fsize = file.tellg() - fsize;
	file.close();

	return fsize;
}

void FilesystemHelper::SaveToFile(string path, DynamicQueue<string> files, string outFile)
{
	unsigned char unsignedCharacter;
	char character;

	vector<StringData> fileNames; //file names
	StringData data;

	while (true)
	{
		if (files.IsEmpty())
		{
			break;
		}

		data.str = files.Dequeue();
		string fullPath = path + data.str;

		data.lenght = this->GetFileSize(fullPath.c_str());

		fileNames.push_back(data);
	}

	ofstream outfile(outFile, ios::out | ios::binary);
	if (!outfile)
	{
		cout << "The file " << outFile << " could not be opened!" << endl;
		exit(1);
	}

	//outreeut file format: filename1, filelength1, file1, ...
	for (unsigned int i = 0;i < fileNames.size();++i)
	{
		cout << "Reading " << fileNames.at(i).str << endl;

		outfile.write(fileNames.at(i).str.c_str(), fileNames.at(i).str.size());
		//add a next line char to the end of the file name
		character = '\n';
		unsignedCharacter = character;
		outfile.put(unsignedCharacter);

		//write the file length
		//divide 32 bit u. int values into 4 bytes
		outfile.put(static_cast<unsigned char>(fileNames.at(i).lenght >> 24));
		outfile.put(static_cast<unsigned char>((fileNames.at(i).lenght >> 16) % 256));
		outfile.put(static_cast<unsigned char>((fileNames.at(i).lenght >> 8) % 256));
		outfile.put(static_cast<unsigned char>(fileNames.at(i).lenght % 256));

		//write the file 
		string filePath = path + fileNames.at(i).str;
		ifstream infile(filePath.c_str(), ios::in | ios::binary);
		int length = fileNames.at(i).lenght;
		for (unsigned int j = 0;j < length;++j)
		{
			infile.get(character);
			outfile.put(character);
		}

		infile.clear(); //clear the EOF flag
		infile.seekg(0); //reset get() pointer to beginning
		infile.close();
	}
}

void FilesystemHelper::RestoreDirectory(string compressedDirectory, string targetDirectory)
{
	unsigned char unsignedCharacter;
	char character;

	ifstream infile(compressedDirectory, ios::in | ios::binary);
	if (!infile)
	{
		std::cout << "The file " << compressedDirectory << " could not be opened!" << endl;
		return;
	}

	cout << "Creating files" << endl;

	string fileName;
	unsigned int length;
	while (true)
	{
		//get the file name
		getline(infile, fileName);
		if (fileName.empty())
		{
			break;
		}

		cout << "Extracting " << fileName << endl;
		// Get the file length by reading 4 bytes and combine them into 32 bit unsigned int 
		length = 0;
		for (int k = 3;k >= 0;--k)
		{
			infile.get(character);
			unsignedCharacter = character;
			length += unsignedCharacter*(1 << (8 * k));
		}

		string pathToWrite = targetDirectory + fileName;
		ofstream outfile(pathToWrite, ios::out | ios::binary);
		if (!outfile)
		{
			int indexOfDirectory = fileName.find_last_of("\\");
			int startOfDirectory = fileName.find_last_of("\\", indexOfDirectory - 1);

			string directoryName = targetDirectory + fileName.substr(0, indexOfDirectory);
			CreateDirectory(directoryName.c_str(), NULL);

			outfile.close();
			outfile.open(pathToWrite);

			if (!outfile)
			{
				outfile.close();

				int start = 0;
				int end = fileName.find("\\", start);

				while (true)
				{
					string path = targetDirectory + fileName.substr(0, end);
					WIN32_FIND_DATA fd;
					HANDLE hFind = ::FindFirstFile(path.c_str(), &fd);

					if (fd.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
					{
						CreateDirectory(path.c_str(), NULL);
					}

					start = end;
					end = fileName.find("\\", start + 1);

					if (end == -1)
					{
						break;
					}
				}

				outfile.open(pathToWrite);
			}
		}

		for (unsigned int i = 0;i < length;++i)
		{
			infile.get(character);
			outfile.put(character);
		}

		outfile.close();
	}

	infile.close();
	remove(compressedDirectory.c_str());
}

void FilesystemHelper::TraverseDirectory(string path, string folder, DynamicQueue<string>& files)
{
	DynamicQueue<string> folders; //Will be added to List

	char search_path[200];
	string pathtoSearch = path + folder;

	sprintf_s(search_path, "%s*.*", pathtoSearch.c_str());
	WIN32_FIND_DATA folderData;
	HANDLE hFind = ::FindFirstFile(search_path, &folderData);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			// read all (real) files in current folder, delete '!' read other 2 default folder . and ..
			if (!(folderData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
			{
				files.Enqueue(folder + folderData.cFileName);
			}
			else //Put folders into vector
			{
				folders.Enqueue(folderData.cFileName);
			}
		} while (::FindNextFile(hFind, &folderData));
		::FindClose(hFind);

		folders.Dequeue();
		folders.Dequeue();

		while (!folders.IsEmpty())
		{
			string nextFolder = folders.Dequeue();
			TraverseDirectory(path, folder + nextFolder + "\\", files);
		}
	}
}
