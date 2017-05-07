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

template<typename T>
class ListNode
{
public:
	T value;

	ListNode* next;

	ListNode(T value);

	ListNode(T value, ListNode* prev);
};
