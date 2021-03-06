// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Hash.h"
#include <conio.h>
#include <fstream>


int main(){

	Hash hashObj;
	string curWord;

	// add dictionary words to tree
	ifstream* inStream = new ifstream();
	inStream->open("dictionary.txt", fstream::in);

	//inseart each word
	while (getline(*inStream, curWord))
	{
		hashObj.AddItem(curWord);
	}

	hashObj.PrintTable();
	cout << endl << "Number of collissions:  " << hashObj.collisions << endl << endl << endl;


	string docStringStr;
	char* stringPart;

	inStream->close();
	inStream->clear();
	inStream->open("mispelled.txt", fstream::in);
	getline(*inStream, docStringStr);

	char* docString = const_cast<char*>(docStringStr.c_str());
	char* nextToken = NULL;

	stringPart = strtok_s(docString, " ,.()#&\"123", &nextToken);

	cout << endl << endl << "Misspelled words: " << endl;
	cout << "------------------" << endl;

	int counter = 0;

	while (stringPart != NULL)
	{
		//convert word to lower case
		for (unsigned int i = 0; i < strlen(stringPart); ++i)
		{
			stringPart[i] = tolower(stringPart[i]);
		}

		if (!hashObj.FindWord(stringPart))
		{
			cout << stringPart << ", ";
		}

		stringPart = strtok_s(NULL, " ,.()#&\"123", &nextToken);
	}




	cin.ignore();

    return 0;
}

