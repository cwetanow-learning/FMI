/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task 1
* @compiler VC>
*
*/

//#include "stdafx.h"
#include <iostream>
#include <string> 
#include <iomanip>

#include <vector>
#include <sstream>
#include <fstream>

#include "Operator.h"
#include "Stack.cpp"
#include "DynamicArray.cpp"

bool IsSign(std::string character) {
	return character == "+" ||
		character == "*" ||
		character == "-" ||
		character == "/";
}

DynamicArray<std::string> SplitString(const std::string &str, char delimeter) {
	std::stringstream stream;
	stream.str(str);
	std::string item;

	DynamicArray<std::string> elements;

	while (std::getline(stream, item, delimeter)) {
		elements.Add(item);
	}

	return elements;
}

double Calculate(double leftSide, double rightSide, std::string sign) {
	return sign == "+" ? leftSide + rightSide
		: sign == "-" ? leftSide - rightSide
		: sign == "*" ? leftSide*rightSide
		: leftSide / rightSide;
}

double EvaluateExpression(std::string expression) {
	double result = 0;

	Stack<double> stackWithNumbers;

	DynamicArray<std::string> splittedExpression = SplitString(expression, ' ');

	int expressionLen = splittedExpression.Count();
	for (int i = 0; i < expressionLen; i++)
	{
		std::string str = splittedExpression.ElementAt(i);
		if (IsSign(str))
		{
			try
			{
				double rightSide = stackWithNumbers.Pop();
				double leftSide = stackWithNumbers.Pop();

				double result = Calculate(leftSide, rightSide, str);

				stackWithNumbers.Push(result);
			}
			catch (const std::exception&)
			{
				std::cout << "error";
			}
		}
		else
		{
			double number = std::stod(str);
			stackWithNumbers.Push(number);
		}
	}

	result = stackWithNumbers.Pop();

	return result;
}

std::string PrefixToPostfix(std::string prefix) {
	DynamicArray<std::string> splittedPostfix = SplitString(prefix, ' ');

	Stack<std::string> postfix = Stack<std::string>();

	int postfixLength = splittedPostfix.Count();

	for (int i = postfixLength - 1; i > -1; i--)
	{
		try
		{
			double converted = std::stod(splittedPostfix.ElementAt(i));

			postfix.Push(splittedPostfix.ElementAt(i));
		}
		catch (const std::exception&)
		{
			std::string leftSide = postfix.Pop();
			std::string rightSide = postfix.Pop();

			std::string newExpression = leftSide + ' ' + rightSide + ' ' + splittedPostfix.ElementAt(i);

			postfix.Push(newExpression);
		}
	}

	return postfix.Pop();
}

DynamicArray<Operator*> GetOperatorsFromFile(std::string filePath) {
	std::ifstream infile(filePath);

	char sign;
	char character;
	bool isRight;

	DynamicArray<Operator*> result;
	while (infile >> character >> sign >> isRight)
	{
		Operator* op = new Operator(character, sign, isRight);
		result.Add(op);
	}

	return result;
}

char FindSign(DynamicArray<Operator*> operators, char letter) {
	int length = operators.Count();
	for (int i = 0; i < length; i++)
	{
		if (operators.ElementAt(i)->GetCharacter() == letter)
		{
			return operators.ElementAt(i)->GetSign();
		}
	}
}

std::string ReplaceWithOperators(std::string postfix, DynamicArray<Operator*> operators) {
	DynamicArray<std::string> splittedPostfix = SplitString(postfix, ' ');
	std::string result;

	int postfixLen = splittedPostfix.Count();
	for (int i = 0; i < postfixLen; i++)
	{
		try
		{
			std::stod(splittedPostfix.ElementAt(i));
			result = result + (i == 0 ? "" : " ") + splittedPostfix.ElementAt(i);
		}
		catch (const std::exception&)
		{
			char sign = FindSign(operators, splittedPostfix.ElementAt(i)[0]);

			result = result + (i == 0 ? "" : " ") + sign;
		}
	}

	return result;
}

std::string GetPrefixExpression(std::string fileName) {
	std::ifstream infile(fileName);

	if (infile.good())
	{
		std::string sLine;
		std::getline(infile, sLine);
		return sLine;
	}
}

bool IsValidPrefix(std::string prefix, DynamicArray<Operator*> operators) {
	for each (char character in prefix)
	{
		if ((character < 48 || character>57))
		{
			if ((character != ' ' && character != '-'))
			{
				bool isInvalid = true;
				int operatorsLen = operators.Count();
		
				for (int i = 0; i < operatorsLen; i++)
				{
					if (character == operators.ElementAt(i)->GetCharacter())
					{
						isInvalid = false;
					}
				}

				if (isInvalid)
				{
					return false;
				}
			}
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	std::string prefix = GetPrefixExpression(argv[1]);

	DynamicArray<Operator*> operators = GetOperatorsFromFile(argv[2]);

	if (IsValidPrefix(prefix, operators))
	{
		std::string postfix = PrefixToPostfix(prefix);

		std::cout << postfix << std::endl;

		postfix = ReplaceWithOperators(postfix, operators);

		double result = EvaluateExpression(postfix);

		std::cout << std::setprecision(5) << result << std::endl;
	}
	else
	{
		std::cout << "Error" << std::endl;
	}

	return 0;
}