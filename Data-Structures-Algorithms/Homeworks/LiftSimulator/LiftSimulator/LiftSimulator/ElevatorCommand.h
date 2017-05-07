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

#pragma once
class ElevatorCommand
{
public:
	ElevatorCommand(int floor, int seconds, bool isGoingUp = false);

	bool IsGoingUp;
	int FloorNumber;
	int SecondsFromStart;
};

