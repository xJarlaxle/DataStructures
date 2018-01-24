#include "stdafx.h"
#include "Validation.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <algorithm> 
#include <regex>



Validation::Validation() {};


string Validation::checkFileName(string message) {
	cout << message << endl;
	getline(cin, Validation::input);
	string input = Validation::input;
	regex d("^[^\\\/<>:|?*\"\\\\]+$"); //for windows files
	regex c("^.*\.(txt)$");

	bool match = false;
	bool match2 = false;
	while (!match || !match2) {
		match = regex_match(input, c);
		match2 = regex_match(input, d);
		if (match && match2) { break; }
		cout << "Incorrect entry, please make sure you're typing in the file extension(.txt).  Also, file names cannot contain <>\"\/:? or |";
		cout << message << endl;
		getline(cin, input);
	}
	return input;

};
