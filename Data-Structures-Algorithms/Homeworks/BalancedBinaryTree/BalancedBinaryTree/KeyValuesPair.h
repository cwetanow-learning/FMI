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

#pragma once
#include <vector>

class KeyValuesPair
{
public:
	KeyValuesPair(int pairKey, std::string value);
	KeyValuesPair(int pairKey);
	KeyValuesPair();

	int key;
	std::vector<std::string> data;

	bool operator==(const KeyValuesPair& other);

	bool operator<(const KeyValuesPair& other);

	bool Remove(std::string value);
	void Add(std::string value);
	bool Search(std::string value);
};

