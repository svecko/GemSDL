#include "LinkedLists.h"

#include <iostream>

void SinglyLinkedList::Node::Push(int x, int y)
{
	Node* tmp = new Node();

	tmp->position.x = x;
	tmp->position.y = y;

	if (start == nullptr)
	{
		start = tmp;
		tmp->next = nullptr;
	}
	else
	{
		Node* p = start;

		while (p->next != nullptr)
		{
			p = p->next;
		}

		p->next = tmp;
		tmp->next = nullptr;
	}
}

void SinglyLinkedList::Node::Print()
{
	Node* p = start;

	while (p != nullptr)
	{
		std::cout << "[Position (x, y)]: " << "(" << p->position.x << ", " << p->position.y << ")" << std::endl;

		p = p->next;
	}
}

Vec2 SinglyLinkedList::Node::GetPosition(int n)
{
	Node* p = start;
	Vec2 tmp;

	int i = 0;
	while (p != nullptr)
	{
		if (i == n)
		{
			tmp.x = p->position.x;
			tmp.y = p->position.y;
			return tmp;
		}
		i++;
		p = p->next;
	}
}



