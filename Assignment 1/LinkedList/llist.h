#pragma once
#include <iostream>
#include "node.h"


using namespace std;

class LinkedList {
private:
	Node * first;
	string inFile;
	string outFile;
	int totalines;

public:
	LinkedList();

	virtual ~LinkedList();

	void add(string line);
	void deleteNode(int nodenum);
	string getValue(int nodenum);
	void insertAtIndex(int index, string nLine);
	friend ostream& operator<<(ostream& output, LinkedList& list);
	int getNumLines();

};