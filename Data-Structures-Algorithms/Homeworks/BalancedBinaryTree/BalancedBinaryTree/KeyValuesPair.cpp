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
#include "KeyValuesPair.h"

KeyValuesPair::KeyValuesPair(int pairKey, std::string value)
{
	key = pairKey;
	data.push_back(value);
}

KeyValuesPair::KeyValuesPair(int pairKey)
{
	key = pairKey;
}

KeyValuesPair::KeyValuesPair()
{
}

bool KeyValuesPair::operator==(const KeyValuesPair & other)
{
	return key == other.key;

}

bool KeyValuesPair::operator<(const KeyValuesPair & other)
{
	return key < other.key;
}

bool KeyValuesPair::Remove(std::string value)
{
	for (size_t i = 0; i < this->data.size(); i++)
	{
		if (data.at(i) == value)
		{
			data.erase(data.begin() + i);
			return true;
		}
	}

	return false;
}

void KeyValuesPair::Add(std::string value)
{
	this->data.push_back(value);
}

bool KeyValuesPair::Search(std::string value)
{
	for (size_t i = 0; i < this->data.size(); i++)
	{
		if (data.at(i) == value)
		{
			return true;
		}
	}

	return false;
}
