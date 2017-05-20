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
#include "Operator.h"

Operator::Operator(char character, char sign, bool isRight)
{
	this->character = character;
	this->sign = sign;
	this->isRight = isRight;
}

Operator::~Operator()
{
}

char Operator::GetCharacter()
{
	return this->character;
}

char Operator::GetSign()
{
	return this->sign;
}

bool Operator::IsRightAssociative() {
	return this->isRight;
}
