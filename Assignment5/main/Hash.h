#pragma once

#include <iostream>
#include <string>

using namespace std;

class Hash {

private:
	//because there are 64 words in the dictionary and 67 is the closest prime number
	static const int tableSize = 53;
	
	struct item {
		string word;
		item* next;
	};

	item* HashTable[tableSize];

public:
	int collisions = 0;
	int hashFunc(string key); //the hash function
	Hash(); //the constructor
	void AddItem(string word); //add the item to the hash table
	int NumberOfItemsAtIndex(int index);
	void PrintTable(); //prints out the HashTable with depth
	bool FindWord(string word); // finds the given word in the hashtable


};
