#include "stdafx.h"
#include "Hash.h"
#include <iostream> 
#include <string>

using namespace std;

//constructor
Hash::Hash() {
	for (int i = 0; i < tableSize; i++) {
		//fill up each index in the hashtable array with a null item
		HashTable[i] = new item;
		HashTable[i]->word = "empty";
		HashTable[i]->next = NULL;
	}
}

//hash function that turns the key into an index value
int Hash::hashFunc(string key) {
	/*int hash = 0;
	int index;
	for (int i = 0; i < key.length(); i++) {

		hash += (int)key[i];
	}
	
	index = hash % tableSize;

	return index;*/

	//https://stackoverflow.com/jobs?utm_source=website&utm_medium=banner&utm_content=leaderboard_6&utm_campaign=house_ads_house_ads_ROS_Docs
	int seed = 101;
	unsigned long hash = 0;
	for (int i = 0; i < key.length(); i++)
	{
		hash = (hash * seed) + key[i];
	}
	return hash % tableSize;
}

//adds the given word to the hashtable and the appropriate key, collisions are handled as well
void Hash::AddItem(string word) {
	int index = hashFunc(word);

	if (HashTable[index]->word == "empty") {
		HashTable[index]->word = word;

	}else {
		//collision handling
		collisions++;
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

//prints the hash table out with depth
void Hash::PrintTable() {
	int number;
	 //Ptr starts at the top item at the index

	for (int i = 0; i < tableSize; i++) {
		number = NumberOfItemsAtIndex(i);
		item* Ptr = HashTable[i];

		//if (Ptr->word != "empty") {
			if (Ptr->word != "empty") {
				if (number > 1) {
					cout << "Index " << i << ":  ";
					while (Ptr != NULL) {
						if (Ptr->next != NULL) {
							cout << Ptr->word << ", ";
						}
						else {
							cout << Ptr->word << endl;
						}
						Ptr = Ptr->next;
					}
				}
				else {
					cout << "Index " << i << ":  " << HashTable[i]->word << endl;
				}
			}
			else {
				cout << "Index " << i << ":  NULL" << endl;
			}
		//}
	}
}

//checks to see if the given word is in the hash table
bool Hash::FindWord(string word) {
	int index = hashFunc(word); //get the index where the word is saved
	bool foundName = false;
	
	item* Ptr = HashTable[index];

	while (Ptr != NULL) {
		if (Ptr->word == word) {
			foundName = true;
		}
		Ptr = Ptr->next;
	}

	return foundName;
}