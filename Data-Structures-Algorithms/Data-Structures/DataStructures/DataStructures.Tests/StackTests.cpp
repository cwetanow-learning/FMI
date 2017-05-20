#include "stdafx.h"
#include "catch.hpp"
#include "../DataStructures/Stack.h"
#include "../DataStructures/Stack.cpp"

TEST_CASE("Stack implementation push tests, should increase size", "[stack]") {
	Stack<int> stack;

	stack.Push(1);
	REQUIRE(stack.GetSize() == 1);
	stack.Push(1);
	REQUIRE(stack.GetSize() == 2);
	stack.Push(1);
	REQUIRE(stack.GetSize() == 3);
	stack.Push(1);
	REQUIRE(stack.GetSize() == 4);

	stack.Clear();
}

TEST_CASE("Pop tests, should decrease size and return correct element", "[stack]") {
	Stack<int> stack;

	stack.Push(1);
	REQUIRE(stack.Pop() == 1);
	REQUIRE(stack.GetSize() == 0);

	stack.Push(2);
	REQUIRE(stack.Pop() == 2);
	REQUIRE(stack.GetSize() == 0);

	stack.Push(3);
	REQUIRE(stack.Pop() == 3);
	REQUIRE(stack.GetSize() == 0);

	stack.Push(4);
	REQUIRE(stack.Pop() == 4);
	REQUIRE(stack.GetSize() == 0);

	stack.Clear();
}

TEST_CASE("Pop tests, should throw when empty") {
	Stack<int> stack;

	REQUIRE_THROWS(stack.Pop());
}

TEST_CASE("Peek tests, should return correct element", "[stack]") {
	Stack<int> stack;

	stack.Push(1);
	REQUIRE(stack.Peek() == 1);

	stack.Push(2);
	REQUIRE(stack.Peek() == 2);

	stack.Push(3);
	REQUIRE(stack.Peek() == 3);

	stack.Push(4);
	REQUIRE(stack.Peek() == 4);

	stack.Clear();
}

TEST_CASE("Peek tests, should throw when empty") {
	Stack<int> stack;

	REQUIRE_THROWS(stack.Peek());
}

TEST_CASE("IsEmpty tests, should return true when empty", "[stack]") {
	Stack<int> stack;

	REQUIRE(stack.IsEmpty());
}

TEST_CASE("IsEmpty tests, should return false when not empty", "[stack]") {
	Stack<int> stack;
	stack.Push(1);

	REQUIRE(!stack.IsEmpty());
}

TEST_CASE("Clear tests, should clear correctly") {
	Stack<int> stack;
	stack.Push(1);

	stack.Clear();
	REQUIRE(stack.IsEmpty());
	REQUIRE(stack.GetSize() == 0);
}