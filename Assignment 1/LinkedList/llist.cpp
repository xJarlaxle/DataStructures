// Some code structure developed by Hal O'Connell on 2012-10-29.
//  Copyright (c) 2012 Hal O'Connell. All rights reserved.

#include <iostream>
#include "llist.h"
#include "stdafx.h"


using namespace std;

LinkedList::LinkedList() : first(nullptr) {};

LinkedList::~LinkedList()
{
	Node *node = first;

	while (node != nullptr)
	{
		Node *temp = node;

		node = node->next;

		if (temp != nullptr) {
			delete temp;
		}
	}
}

void LinkedList::add(string line)
{
	Node *node = new Node();
	node->line = line;
	this->totalines++;

	if (first == nullptr)
	{
		first = node;
	}
	else
	{
		Node *currNode = first;
		Node *prevNode = nullptr;

		while (currNode != nullptr)
		{
			prevNode = currNode;
			currNode = currNode->next;
		}

		if (prevNode != nullptr)
		{
			prevNode->next = node;
		}
	}
}

void LinkedList::deleteNode(int nodenum)
{
	int index = -1;

	Node *node = first;
	Node *prev = nullptr;

	while (node != nullptr)
	{
		index++;

		if (index == nodenum)
		{
			break;
		}

		prev = node;
		node = node->next;
	}

	if (index >= 0)
	{
		if (node == first)
		{
			first = node->next;
		}
		else
		{
			prev->next = node->next;
		}

		delete node;
		totalines--;
	}
} // End method deleteNode

string LinkedList::getValue(int nodenum)
{
	int index = -1;
	string val = "";

	Node *node = first;

	while (node != nullptr)
	{
		index++;

		if (index == nodenum)
		{
			val = node->line;
			break;
		}

		node = node->next;
	}
	return val;
} // End method getValue

void LinkedList::insertAtIndex(int index, string nLine)
{
	Node *node = new Node();
	node->line = nLine;
	totalines++;

	if (index == 0)
	{

		node->next = first;
		first = node;

	}
	else
	{
		index--;
		int i = 0;
		Node *prev = first;

		while (prev != nullptr)
		{
			if (i == index)
			{
				break;
			}

			prev = prev->next;
			i++;
		} // End while

		if (first == nullptr)
		{
			first = node;
		}
		else
		{
			if (prev != nullptr)
			{
				node->next = prev->next;
				prev->next = node;
			}
			else
			{
				add(nLine);
			}
		}
	} // End else
} // End method insertAtIndex

ostream& operator<<(ostream& output, LinkedList& list)
{
	Node *currNode = list.first;
	int i = 0;

	// Loop while not empty
	while (currNode != nullptr)
	{
		output << i << ":   " << currNode->line << endl;
		currNode = currNode->next;
		i++;
	}
	return output;
}

int LinkedList::getNumLines()
{
	return this->totalines;
}

