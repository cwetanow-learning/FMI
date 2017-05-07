/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task 4
* @compiler VC>
*
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

#include "Tree.cpp"
#include "KeyValuesPair.h"
#include "SortedLinkedList.cpp"
#include "Node.h"
#include "ListNode.h"

SortedLinkedList<KeyValuesPair> sortedInput;
Tree<KeyValuesPair> tree;
KeyValuesPair worker;

void Add(int key, std::string input) {
	worker = KeyValuesPair(key);

	KeyValuesPair* found = tree.Find(worker);
	if (!(found == NULL))
	{
		found->Add(input);
	}
	else
	{
		tree.Insert(KeyValuesPair(key, input));
	}
}

void AddToList(int key, std::string data) {
	KeyValuesPair pair = KeyValuesPair(key, data);
	KeyValuesPair* result = sortedInput.Add(pair);

	if (result != NULL)
	{
		result->Add(data);
	}
}

bool Remove(int key, std::string input) {
	worker = KeyValuesPair(key);

	KeyValuesPair* found = tree.Find(worker);
	if (!(found == NULL))
	{
		return found->Remove(input);
	}

	return false;
}

int RemoveAll(int key) {
	worker = KeyValuesPair(key);

	KeyValuesPair* found = tree.Find(worker);
	if (!(found == NULL))
	{
		int result = found->data.size();
		tree.Remove(worker);
		return result;
	}

	return 0;
}

bool Search(int key, std::string value) {
	worker = KeyValuesPair(key);

	KeyValuesPair* found = tree.Find(worker);
	if (!(found == NULL))
	{
		return found->Search(value);
	}

	return false;
}

void ParseInput(std::string input) {
	if (input[0] == 'a')
	{
		std::string stringifiedKey = "";
		std::string data = "";
		bool isKey = true;

		for (int i = 4; i < input.length(); i++)
		{
			char current = input[i];
			if (current == ' ' && isKey)
			{
				isKey = false;
				continue;
			}

			if (isKey)
			{
				stringifiedKey += current;
			}
			else
			{
				data += current;
			}
		}

		Add(std::stoi(stringifiedKey), data);
	}
	else if (input[0] == 's')
	{
		std::string stringifiedKey = "";
		std::string data = "";
		bool isKey = true;

		for (int i = 7; i < input.length(); i++)
		{
			char current = input[i];
			if (current == ' ' && isKey)
			{
				isKey = false;
				continue;
			}

			if (isKey)
			{
				stringifiedKey += current;
			}
			else
			{
				data += current;
			}
		}

		bool result = Search(std::stoi(stringifiedKey), data);
		std::cout << result << std::endl;
	}
	else
	{
		if (input[6] == 'a')
		{
			std::string stringifiedKey = "";

			for (int i = 10; i < input.length(); i++)
			{
				stringifiedKey += input[i];
			}

			int result = RemoveAll(std::stoi(stringifiedKey));
			std::cout << result << std::endl;
		}
		else
		{
			std::string stringifiedKey = "";
			std::string data = "";
			bool isKey = true;

			for (int i = 7; i < input.length(); i++)
			{
				char current = input[i];
				if (current == ' ' && isKey)
				{
					isKey = false;
					continue;
				}

				if (isKey)
				{
					stringifiedKey += current;
				}
				else
				{
					data += current;
				}
			}

			bool result = Remove(std::stoi(stringifiedKey), data);
			std::cout << result << std::endl;
		}
	}
}

void ReadFile(std::string file) {
	std::ifstream reader(file);

	while (!reader.eof())
	{
		int key;
		reader.read((char*)&key, sizeof(key));

		int size = 0;
		reader.read((char*)&size, sizeof(size));

		char *buffer = new char[size + 1];
		reader.read(buffer, size);

		buffer[size] = '\0';

		if (buffer[0] != '\0')
		{
			AddToList(key, buffer);
		}
	}
}

Node<KeyValuesPair>* BuildTree(ListNode<KeyValuesPair>*& node, int start, int end) {
	if (start > end)
	{
		return NULL;
	}

	int mid = (start + end) / 2;

	Node<KeyValuesPair>* left = BuildTree(node, start, mid - 1);
	Node<KeyValuesPair>* root = new Node<KeyValuesPair>();
	root->value = node->value;

	node = node->next;

	Node<KeyValuesPair>* right = BuildTree(node, mid + 1, end);

	root->right = right;
	root->left = left;

	return root;
}

int main(int argc, char** argv)
{
	ReadFile(argv[1]);

	ListNode<KeyValuesPair>* head = sortedInput.getHead();
	int count = sortedInput.count;

	Node<KeyValuesPair>* root = BuildTree(head, 0, count - 1);
	tree = Tree<KeyValuesPair>(root);

	std::string input;
	while (std::getline(std::cin, input))
	{
		ParseInput(input);
	}

	return 0;
}


