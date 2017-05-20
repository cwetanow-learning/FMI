#include "stdafx.h"
#include "RLEString.h"


RLEString::RLEString()
{
	this->root = NULL;
	this->stringLength = 0;
}

RLEString::RLEString(const RLEString & other)
{
	this->root = other.root;
	this->tail = other.tail;
	this->stringLength = other.length();
}


RLEString::~RLEString()
{
}

RLEString * RLEString::operator=(RLEString other)
{
	this->root = other.root;
	this->stringLength = other.length();
	this->tail = other.tail;

	return this;
}

RLEString::RLEString(char const * letters)
{
	size_t len = std::strlen(letters);
	this->stringLength = len;
	int currentLength = 1;
	for (size_t i = 1; i < len; i++)
	{
		char current = letters[i];
		char previous = letters[i - 1];

		if (current == previous)
		{
			++currentLength;
		}
		else
		{
			if (this->root)
			{
				this->tail = new Node(previous, currentLength, this->tail);
			}
			else
			{
				this->root = new Node(previous, currentLength);
				this->tail = this->root;
			}

			currentLength = 1;
		}
	}

	if (this->tail->character != letters[len - 1])
	{
		this->tail = new Node(letters[len - 1], currentLength, this->tail);
	}
}

size_t RLEString::length() const
{
	return this->stringLength;
}

char & RLEString::operator[](int i)
{
	if (i >= this->length() || i < 0)
	{
		throw std::invalid_argument("Index out of range");
	}

	Node* current = this->root;
	int total = current->frequency - 1;

	while (total < i)
	{
		current = current->next;
		total += current->frequency;
	}

	return current->character;
}

RLEString RLEString::operator+(RLEString const & right) const
{
	RLEString result = (*this);
	if (result.tail->character == right.root->character)
	{
		result.tail->frequency += right.root->frequency;
		result.tail->next = right.root->next;
	}
	else
	{
		result.tail->next = right.root;
	}

	result.tail = right.tail;
	result.stringLength += right.length();

	return result;
}

void RLEString::splice(int start, int length)
{
	if (start >= this->length() || start < 0 || start + length >= this->length())
	{
		throw std::invalid_argument("Index out of range");
	}

	Node* current = this->root;
	Node* previous = NULL;
	int total = current->frequency - 1;

	while (total < start)
	{
		previous = current;
		current = current->next;
		total += current->frequency;
	}

	int difference = total + 1 - start;

	current->frequency -= difference;
	length -= difference;

	if (current->frequency > 0)
	{
		previous = current;
	}

	while (length > 0)
	{
		current = current->next;

		difference = current->frequency - length;

		if (difference > 0)
		{
			previous->next = current;

			current->frequency -= length;
			break;
		}
		else if (difference == 0)
		{
			previous->next = current->next;
			break;
		}
		else
		{
			length -= current->frequency;
		}
	}
}

void RLEString::insert(const RLEString & rles, int pos)
{
	if (pos > this->length() || pos < 0)
	{
		throw std::invalid_argument("Index out of range");
	}

	Node* current = this->root;
	Node* previous = NULL;
	int total = current->frequency - 1;

	while (total < pos)
	{
		previous = current;
		current = current->next;
		total += current->frequency;
	}

	if (previous)
	{
		if (total == pos + current->frequency - 1)
		{
			if (previous->character == rles.root->character)
			{
				previous->frequency += rles.root->frequency;
				previous->next = rles.root->next;
			}
			else
			{
				previous->next = rles.root;
			}

			if (rles.tail->character == current->character)
			{
				rles.tail->frequency += current->frequency;
				rles.tail->next = current->next;
			}
			else
			{
				rles.tail->next = current;
			}

			this->stringLength += rles.length();
		}
		else
		{
			size_t left = total - pos + 1;
			current->frequency = previous->frequency - left;
			Node* next = current->next;

			if (current->character == rles.root->character)
			{
				current->frequency += rles.root->frequency;
				current->next = rles.root->next;
			}
			else
			{
				current->next = rles.root;
			}

			if (rles.tail->character == current->character)
			{
				rles.tail->frequency += left;
				rles.tail->next = next;
			}
			else
			{
				Node* newNode = new Node(current->character, left, rles.tail);
				newNode->next = next;
			}

			this->stringLength += rles.length();
		}
	}
}

std::ostream & operator<<(std::ostream & os, const RLEString &str)
{
	RLEString::Node* current = str.root;

	while (current)
	{
		os << "(" << current->frequency << ", " << current->character << ") ";
		current = current->next;
	}

	return os;
}
