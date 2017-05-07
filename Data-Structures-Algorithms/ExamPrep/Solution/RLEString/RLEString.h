#include <iostream>

#pragma once


class RLEString
{
private:
	class Node {
	public:
		char character;
		int frequency;
		Node* next;

		Node(char ch, int freq) {
			character = ch;
			frequency = freq;
			next = NULL;
		}

		Node(char ch, int freq, Node* previous) {
			character = ch;
			frequency = freq;
			next = NULL;

			previous->next = this;
		}

		Node* operator=(Node other) {

		};

	};

	size_t stringLength;
	Node* root;
	Node* tail;

public:
	RLEString();
	RLEString(const RLEString& other);
	~RLEString();

	RLEString* operator=(RLEString other);

	RLEString(char const * letters);

	friend std::ostream& operator<<(std::ostream& os, const RLEString&);

	size_t length() const;

	char& operator[](int i);

	RLEString operator+(RLEString const & right) const;

	void splice(int start, int length);

	void insert(const RLEString& rles, int pos);
};

