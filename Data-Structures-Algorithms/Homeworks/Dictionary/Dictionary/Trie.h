#include<string.h>
#include<iostream>

#include "Node.h"

#pragma once
class Trie
{
public:
	Trie();

	void AddWord(std::string word, double weight);
	bool HasWord(std::string word);
	double GetWordWeight(std::string word);

private:
	Node* root;
};

