#include "stdafx.h"
#include "Trie.h"


Trie::Trie()
{
	root = new Node();
}

void Trie::AddWord(std::string word, double weight)
{
	if (word.length() == 0)
	{
		return;
	}

	Node* current = root;


	for (int i = 0; i < word.length(); i++)
	{
		std::string currentWord = word[i] + "";
		i++;

		while (i < word.length() && isalpha(word[i]))
		{
			currentWord += word[i];
			i++;
		}

		Node* child = current->FindChild(currentWord);

		if (child != NULL)
		{
			current = child;
			if (currentWord == word)
			{
				current->SetWeight(weight);
			}
		}
		else
		{
			Node* newNode;

			if (i >= word.length() - 2)
			{
				newNode = new Node(currentWord, weight);
			}
			else
			{
				newNode = new Node(currentWord);
			}

			current->children.push_back(newNode);
			current = newNode;
		}
	}
}

bool Trie::HasWord(std::string word)
{
	Node* current = root;

	for (int i = 0; i < word.length(); i++)
	{
		std::string currentWord = word[i] + "";
		i++;

		while (i < word.length() && isalpha(word[i]))
		{
			currentWord += word[i];
			i++;
		}

		Node* child = current->FindChild(currentWord);

		if (child != NULL)
		{
			current = child;
		}
		else
		{
			return false;
		}
	}

	return true;
}

double Trie::GetWordWeight(std::string word)
{
	Node* current = root;

	for (int i = 0; i < word.length(); i++)
	{
		std::string currentWord = word[i] + "";
		i++;

		while (i < word.length() && isalpha(word[i]))
		{
			currentWord += word[i];
			i++;
		}

		Node* child = current->FindChild(currentWord);

		if (child != NULL)
		{
			current = child;
		}
		else
		{
			return 0;
		}
	}

	return current->GetWeight();
}
