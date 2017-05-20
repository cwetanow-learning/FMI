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

#pragma once
class Operator
{
public:
	Operator(char character, char sign, bool isRight);
	~Operator();

	char GetCharacter();
	char GetSign();
	bool IsRightAssociative();

private:
	char character;
	char sign;
	bool isRight;
};

