#include "stdafx.h"
#include "Hash.h"
#include <iostream> 
#include <string>

using namespace std;

Hash::Hash() {
	for (int i = 0; i < tableSize; i++) {
		//fill up each index in the hashtable array with a null item
		HashTable[i] = new item;
		HashTable[i]->word = "empty";
		HashTable[i]->next = NULL;
	}
}

int Hash::hashFunc(string key) {
	int hash = 0;
	int index;
	for (int i = 0; i < key.length(); i++) {

		hash += (int)key[i];
	}
	
	index = hash % tableSize;

	return index;
}

void Hash::AddItem(string word) {
	int index = hashFunc(word);

	if (HashTable[index]->word == "empty") {
		HashTable[index]->word = word;

	}else {
		//collision handling
		item* Ptr = HashTable[index]; //point to the first item at the index
		item* n = new item;
		n->word = word;
		n->next = NULL;
		//sets the Ptr pointer to the item at the end of the list
		while (Ptr->next != NULL) {
			Ptr = Ptr->next;
		}
		//sets the item at the end equal to the new item
		Ptr->next = n;
	}
}

//gets the depth of the index
int Hash::NumberOfItemsAtIndex(int index) {
	int count = 0;
	if (HashTable[index]->word == "empty") {
		return count;
	}else {
		count++;
		item* Ptr = HashTable[index];
		while (Ptr->next != NULL) {
			count++;
			Ptr = Ptr->next;
		}
	}

	return count;
}

void Hash::PrintTable() {
	//holds number of elements at each index
	int number;
	for (int i = 0; i < tableSize; i++) {

	}

}