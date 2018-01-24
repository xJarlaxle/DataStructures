#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"
#include "Validation.h"
#include <fstream>
#include <conio.h>
#include <iostream>
#include <string>
#include <algorithm> 



using namespace std;

Validation val;
string inFile, outFile, line, input, tempLine;
LinkedList contents;
int totalLines, changeLine, rangeStart, rangeEnd, currentLine = 0;

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
			cout << i << " " << list.getValue(i) << endl;
		}
		//fout.fail() for a creation error
		if (fout.fail()) {
			fout.close();
			throw "Error accessing/creating C:\\Users\\NSCCStudent\\Desktop\\" + outFile + " for output.";
		}
		//fout.close();
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
	system("cls");
	cout << "--------------------------------------" << endl;
	cout << "    WELCOME TO BASIC TEXT EDITOR" << endl;
	cout << "--------------------------------------" << endl;
	cout << endl << endl;
	do {
		totalLines = contents.getNumLines();
		if ((currentLine) > (totalLines - 1)) {
			currentLine = (totalLines - 1);
			if (currentLine < 0) {
				currentLine = 0;
			}
		}
		cout << ">>(" << currentLine << "): ";
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input[0] == 'I') {
			if (isdigit(input[1])) {
				changeLine = input[1] - 48;
				cout << "Enter in change: ";
				getline(cin, tempLine);
				contents.insertAtIndex(changeLine, tempLine);
			}
			else {
				cout << "Enter in change: ";
				getline(cin, tempLine);
				contents.insertAtIndex(currentLine, tempLine);
			}
		}
		else if (input[0] == 'D') {
			if (isdigit(input[1])) {
				rangeStart = input[1] - 48;
				if (isdigit(input[2])) {
					rangeEnd = input[2] - 48;
					int numOfLoops = (rangeEnd - rangeStart) + 1;
					for (int i = rangeStart; i <= numOfLoops; i++) {
						contents.deleteNode(rangeStart);
					}
				}
				else {
					contents.deleteNode(rangeStart);
				}
			}
			else {
				contents.deleteNode(currentLine);
			}
		}
		else if (input[0] == 'V') {
			cout << contents << endl;
		}
		else if (input[0] == 'G') {
			if (isdigit(input[1])) {
				currentLine = input[1] - 48;
			}
			else {
				currentLine = 0;
			}
		}
		else if (input[0] == 'L') {
			if (isdigit(input[1])) {
				rangeStart = input[1] - 48;
				if (isdigit(input[2])) {
					rangeEnd = input[2] - 48;
					for (int i = rangeStart; i <= rangeEnd; i++) {
						cout << i << ":   " << contents.getValue(i) << endl;
					}
				}
				else {
					cout << rangeStart << ":   " << contents.getValue(rangeStart) << endl;
				}
			}
			else {
				cout << currentLine << ":   " << contents.getValue(currentLine) << endl;
			}
		}
		else if (input[0] == 'S') {
			if (isdigit(input[1])) {
				changeLine = input[1] - 48;
				cout << "Enter in substitution: ";
				getline(cin, tempLine);
				contents.insertAtIndex(changeLine, tempLine);
				contents.deleteNode((changeLine + 1));
			}
			else {
				cout << "Enter in substitution: ";
				getline(cin, tempLine);
				contents.insertAtIndex(currentLine, tempLine);
				contents.deleteNode((currentLine + 1));
			}

			cout << endl << contents << endl;
		}
		else if (input[0] == 'E') {
			writeOut(contents);
			break;
		}

	} while (input != "Q");

	return 0;
}
























