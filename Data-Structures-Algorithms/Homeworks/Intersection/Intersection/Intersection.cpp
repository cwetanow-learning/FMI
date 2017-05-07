/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task 5
* @compiler VC>
*
*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Tree.cpp"

int main()
{
	int n;

	std::cin >> n;

	Tree<long> initial;
	Tree<long> helper;

	std::string input;
	std::cin >> input;
	std::ifstream reader(input);

	while (!reader.eof())
	{
		long nextNumber = 0;
		reader.read((char*)nextNumber, sizeof(nextNumber));

		initial.Insert(nextNumber);
	}

	reader.close();
	--n;

	while (n > 0)
	{
		std::ifstream reader(input);

		while (!reader.eof())
		{
			long nextNumber = 0;
			reader.read((char*)nextNumber, sizeof(nextNumber));

			if (initial.Contains(nextNumber))
			{
				helper.Insert(nextNumber);
			}
		}

		reader.close();

		initial = helper;
		helper = Tree<long>();

		--n;
	}

	std::vector<long> list;
	initial.Traverse(list);

	std::ofstream writer("result.bin", std::ios::binary);

	for (size_t i = 0; i < list.size(); i++)
	{
		long num = list.at(i);
		writer.write((char*)&num, sizeof(long));
	}

	writer.close();

	return 0;
}

