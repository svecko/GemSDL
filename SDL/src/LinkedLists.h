#pragma once

#include "Vec2.h"

namespace SinglyLinkedList
{
	struct Node
	{
		Vec2 position;

		Node* next;

		static void Push(int x, int y);
		static void Print();
		static Vec2 GetPosition(int n);
	} static* start = nullptr;
}

namespace DoublyLinkedList
{
	struct Node
	{
		Vec2 position;

		Node* prev;
		Node* next;

		static void Push(int x, int y);
		// static void Print();
	} static* start = nullptr, * end = nullptr;
}
