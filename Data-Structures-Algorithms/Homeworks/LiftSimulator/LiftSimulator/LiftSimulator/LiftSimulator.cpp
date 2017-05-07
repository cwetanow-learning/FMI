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
#include <fstream>
#include <iostream>
#include <string>
#include <cmath> 

#include "./ElevatorCommand.h"
#include "./DynamicArray.cpp"

using namespace std;

string GetSplittedPartOfStringByPosition(string str, int position, char delimeter) {
	string result = "";
	int delimetersFound = 0;

	for (string::size_type i = 0; i < str.size(); i++)
	{
		if (str[i] == delimeter)
		{
			++delimetersFound;
			continue;
		}

		if (delimetersFound > position)
		{
			break;
		}

		if (delimetersFound == position)
		{
			result += str[i];
		}
	}

	return result;
}

ElevatorCommand* ParseCommand(string commandLine) {
	string commandType = GetSplittedPartOfStringByPosition(commandLine, 0, ' ');

	bool isGoingUp = false;
	int floorNumber;
	int secondsFromStart;

	if (commandType == "call")
	{
		isGoingUp = GetSplittedPartOfStringByPosition(commandLine, 1, ' ') == "up";
		floorNumber = stoi(GetSplittedPartOfStringByPosition(commandLine, 2, ' '));
		secondsFromStart = stoi(GetSplittedPartOfStringByPosition(commandLine, 3, ' '));
	}
	else
	{
		floorNumber = stoi(GetSplittedPartOfStringByPosition(commandLine, 1, ' '));
		secondsFromStart = stoi(GetSplittedPartOfStringByPosition(commandLine, 2, ' '));
	}

	return new ElevatorCommand(floorNumber, secondsFromStart, isGoingUp);
}

bool CommandIsBetweenFloors(int currentFloor, int destinationFloor, int targetedFloor, bool isDirectionUp) {
	bool result;

	if (isDirectionUp)
	{
		result = currentFloor <= targetedFloor&& targetedFloor <= destinationFloor;
	}
	else
	{
		result = currentFloor >= targetedFloor&& targetedFloor >= destinationFloor;
	}

	return result;
}

void PrintArrived(int time, int floor, bool isDirectionUp) {
	cout << time << " " << floor << " " << (isDirectionUp ? "up" : "down") << endl;
}

int main(int argc, char** argv)
{
	const int secondsPerFloor = 5;

	ifstream file(argv[1]);

	if (file)
	{
		string line;
		getline(file, line);

		int	numberOfFloors = stoi(GetSplittedPartOfStringByPosition(line, 0, ' '));
		int	numberOfRequests = stoi(GetSplittedPartOfStringByPosition(line, 1, ' '));

		DynamicArray<ElevatorCommand*> commands = DynamicArray<ElevatorCommand*>(numberOfRequests);

		while (getline(file, line))
		{
			ElevatorCommand* command = ParseCommand(line);
			commands.Add(command);
		}

		int totalElapsedTime = commands.ElementAt(0)->SecondsFromStart;
		bool isCurrentDirectionUp = true;

		int currentFloor = 1;

		int requestsExecuted = 0;

		DynamicArray<ElevatorCommand*> commandsToBeExecuted;
		commandsToBeExecuted.Add(commands.ElementAt(0));
		commands.RemoveAt(0);

		while (requestsExecuted != numberOfRequests)
		{
			if (commandsToBeExecuted.Count() == 0)
			{
				commandsToBeExecuted.Add(commands.ElementAt(0));
				totalElapsedTime = totalElapsedTime > commandsToBeExecuted.ElementAt(0)->SecondsFromStart ?
					totalElapsedTime :
					commandsToBeExecuted.ElementAt(0)->SecondsFromStart;
				commands.RemoveAt(0);
			}

			int nextFloor = commandsToBeExecuted.ElementAt(0)->FloorNumber;
			isCurrentDirectionUp = currentFloor < nextFloor;

			int allCommandsCount = commands.Count();
			for (int i = 0; i < allCommandsCount; i++)
			{
				int nextElementFloor = commands.ElementAt(i)->FloorNumber;

				if (commands.ElementAt(i)->SecondsFromStart > totalElapsedTime)
				{
					break;
				}
				else
				{
					if (CommandIsBetweenFloors(currentFloor, nextFloor, nextElementFloor, isCurrentDirectionUp))
					{
						for (int j = 0; j < commandsToBeExecuted.Count(); j++)
						{
							if (isCurrentDirectionUp &&
								nextElementFloor <= commandsToBeExecuted.ElementAt(j)->FloorNumber)
							{
								commandsToBeExecuted.Insert(commands.ElementAt(i), j);
								break;
							}
							else if (!isCurrentDirectionUp &&
								nextElementFloor >= commandsToBeExecuted.ElementAt(j)->FloorNumber)
							{
								commandsToBeExecuted.Insert(commands.ElementAt(i), j);
								break;
							}
						}

						commands.RemoveAt(i);

						--i;
						--allCommandsCount;
					}
				}
			}

			nextFloor = commandsToBeExecuted.ElementAt(0)->FloorNumber;

			if (nextFloor == currentFloor)
			{
				++requestsExecuted;
				PrintArrived(totalElapsedTime, currentFloor, isCurrentDirectionUp);
				commandsToBeExecuted.RemoveAt(0);

				continue;
			}

			totalElapsedTime += 5;

			currentFloor = isCurrentDirectionUp ? currentFloor + 1 : currentFloor - 1;

			if (currentFloor == nextFloor)
			{
				PrintArrived(totalElapsedTime, currentFloor, isCurrentDirectionUp);

				while (currentFloor == nextFloor)
				{
					commandsToBeExecuted.RemoveAt(0);
					++requestsExecuted;

					if (commandsToBeExecuted.Count() == 0)
					{
						break;
					}
					nextFloor = commandsToBeExecuted.ElementAt(0)->FloorNumber;
				}
			}
		}

		file.close();
	}

	return 0;
}

