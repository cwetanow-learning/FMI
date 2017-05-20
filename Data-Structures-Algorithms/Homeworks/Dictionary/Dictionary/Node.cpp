#include "stdafx.h"
#include "Node.h"

Node::Node() {
	this->children = std::vector<Node*>();
}

std::string Node::GetCharacter()
{
	return this->character;
}

double Node::GetWeight()
{
	return this->weight;
}

void Node::SetWeight(double value) {
	this->weight = value;
}

Node * Node::FindChild(std::string wordToSearch)
{
	for (int i = 0; i < children.size(); i++)
	{
		if (children.at(i)->character == wordToSearch) {
			return children.at(i);
		}
	}

	return NULL;
}

Node::Node(std::string character, double weight)
{
	this->character = character;
	this->weight = weight;
	this->children = std::vector<Node*>();
}