/**
*
* Solution to homework task
* Data Structures Course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Ivan Mladenov
* @idnumber 91650
* @task
* @compiler VC>
*
*/

#include<iostream>
#include<fstream>
#include<string>

using namespace std;
#pragma once
// Huffman Tree
class Tree
{
private:
	class Node
	{
	public:
		unsigned int frequency;
		unsigned char character;
		Node* left;
		Node* right;

		Node(void) {
			frequency = 0;
			character = '\0';
			left = NULL;
			right = NULL;
		}
	};

	Node *root;

	Tree(const Tree &);
	const Tree & operator=(const Tree &);
	void chop(Node * N);

public:
	Tree(void);
	~Tree(void);

	unsigned int get_freq(void) const;
	unsigned char get_char(void) const;
	void set_freq(unsigned int);
	void set_char(unsigned char);
	Node* get_left(void) const;
	Node* get_right(void) const;
	void set_left(Node *);
	void set_right(Node *);
	Node* get_root(void) const;

	bool operator==(const Tree &) const;
	bool operator!=(const Tree &) const;
	bool operator<(const Tree &) const;
	bool operator>(const Tree &) const;
	bool operator<=(const Tree &) const;
	bool operator>=(const Tree &) const;

	// Gets the binary representation of a path to a specific character
	void GetBinaryString(Node * node, unsigned char character, string currentPath, string & result);

	// Finds the character of the binary string
	bool GetCharacter(string binaryString, unsigned char & character);
};