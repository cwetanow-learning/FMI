#include<string.h>
#include<iostream>
#include <vector>

#pragma once
class Node
{
public:
	std::string GetCharacter();
	double GetWeight();
	void SetWeight(double value);

	std::vector<Node*> children;
	Node* FindChild(std::string c);

	Node(std::string character, double weight = 0);
	Node();

private:
	std::string character;
	int weight;
};

