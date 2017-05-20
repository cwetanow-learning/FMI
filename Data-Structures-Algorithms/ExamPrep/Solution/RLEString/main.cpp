// RLEString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "RLEString.h"

int main()
{
	char* arr = "AAABBCBBC";

	RLEString str = RLEString(arr);

	str.splice(2, 5);
	std::cout << str;

	return 0;
}

