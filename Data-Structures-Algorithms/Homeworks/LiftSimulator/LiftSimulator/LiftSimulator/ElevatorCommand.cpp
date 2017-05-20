/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task 2
* @compiler VC>
*
*/

#include "stdafx.h"
#include "ElevatorCommand.h"

ElevatorCommand::ElevatorCommand(int floor, int seconds, bool isGoingUp )
{
	this->FloorNumber = floor;
	this->IsGoingUp = isGoingUp;
	this->SecondsFromStart = seconds;
}
