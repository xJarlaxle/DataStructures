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
	cout << endl << "Number of collissions:  " << hashObj.collisions << endl;

	cin.ignore();

    return 0;
}

