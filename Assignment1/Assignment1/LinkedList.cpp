//
//  main.cpp
//  linkedlist
//
//  Created by Hal O'Connell on 2012-10-29.
//  Copyright (c) 2012 Hal O'Connell. All rights reserved.
//
#include <iostream>
#include "LinkedList.h"
#include "Validation.h"
#include <fstream>
#include <conio.h>
#include <iostream>
#include <string>




using namespace std;

Validation val;
string inFile, outFile, line;
LinkedList contents;
int totalLines = 4;

void readIn(string fileIn) {

	try {

		//creates the instream and gives it the file path
		string filePath = "C:\\Users\\NSCCStudent\\Desktop\\" + fileIn;
		ifstream fin(filePath);
		//fin.fail() is there is problems opening the file path.
		if (fin.fail()) {
			throw "Couldn't open the file.  Make sure C:\\Users\\NSCCStudent\\Desktop\\" + fileIn + " exists.";
		}

		while (!fin.eof()) {
			getline(fin, line);
			contents.add(line);
			totalLines++;

			//if the program can't read the line for some reason
			if (fin.fail()) {
				// failed to read in
				fin.close();
				//fout.close();
				throw "Line reading error.";
			}//end if
		}//end while
		fin.close();
	}//end try
	catch (...) {
		cout << "Error 100: An error occurred while reading in the file.";

	}



};

void writeOut(LinkedList list) {
	//creates the outstream for the html file to be places
	try {
		ofstream fout("C:\\Users\\NSCCStudent\\Desktop\\" + outFile);
		totalLines = list.getNumLines();
		for (int i = 0; i < totalLines; i++) {
			fout << list.getValue(i) << endl;
		}
		//fout.fail() for a creation error
		if (fout.fail()) {
			fout.close();
			throw "Error accessing/creating C:\\Users\\NSCCStudent\\Desktop\\" + outFile + " for output.";
		}
		fout.close();
	}
	catch (...) {
		cout << "Error 200: Something went wrong..";
	}
}


int main()
{
	inFile = val.checkFileName("Enter in the file to read from (something.txt):  ");
	outFile = val.checkFileName("Enter in a destination file (something.txt):  ");
	
	readIn(inFile);
	cout << endl << endl;
	cout << contents;

	contents.insertAtIndex(3, "sweet");

	contents.deleteNode(3);
	
	writeOut(contents);
	cin.ignore();
	return 0;
}
