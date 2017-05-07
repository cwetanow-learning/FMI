// Dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Trie.h"

#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <vector>

#include "DynamicArray.h"

using namespace std;

vector<std::string> SplitString(const std::string &str, char delimeter) {
	std::stringstream stream;
	stream.str(str);
	std::string item;

	vector<std::string> elements;

	while (std::getline(stream, item, delimeter)) {
		elements.push_back(item);
	}

	return elements;
}

Trie* GetDictionary(string fileName) {
	Trie* trie = new Trie();

	ifstream file(fileName);

	if (file)
	{
		string line;

		while (getline(file, line))
		{
			vector<string> input = SplitString(line, ' ');

			string result = "";

			for (int i = 0; i < input.size() - 1; i++)
			{
				if (input.at(i).length() > 0) {
					string content = input.at(i);

					for (int j = 0; j < content.length(); j++)
					{
						result += tolower(content[j]);
					}

					result += " ";
				}
			}

			int weight = stoi(input.at(input.size() - 1));

			trie->AddWord(result, weight);
		}

		file.close();
	}

	return trie;
}

int main(int argc, char** argv)
{
	Trie* trie = GetDictionary(argv[1]);

	for (int i = 2; i < argc; i++)
	{
		ifstream file(argv[i]);

		if (file)
		{
			string words;
			double score = 0.0;
			int spaceCounters = 0;
			string currentWord = "";

			while (getline(file, words))
			{
				for (int i = 0; i < words.length(); i++)
				{
					if (!isalpha(words[i]))
					{
						continue;
					}

					if (currentWord.length() == 0)
					{
						currentWord += tolower(words[i]);
						i++;
					}

					while (i < words.length() && isalpha(words[i]))
					{
						currentWord += tolower(words[i]);
						i++;
					}

					spaceCounters++;

					if (!trie->HasWord(currentWord))
					{
						currentWord = "";
						continue;
					}

					double currentScore = 0.0;

					while (trie->HasWord(currentWord))
					{
						currentWord += ' ';
						int j = i;
						while (trie->GetWordWeight(currentWord) == 0)
						{
							j++;

							while (j < words.length() && isalpha(words[j]))
							{
								currentWord += tolower(words[j]);
								j++;
							}

							currentWord += ' ';

							if (!trie->HasWord(currentWord))
							{
								break;
							}

							spaceCounters++;
							i = j;
						}

						double weight = trie->GetWordWeight(currentWord);
						currentScore = weight == 0 ? currentScore : weight;
					}

					score += currentScore;
					currentWord = "";
				}
			}

			cout << (score / spaceCounters);
			file.close();
		}
	}

	return 0;
}

