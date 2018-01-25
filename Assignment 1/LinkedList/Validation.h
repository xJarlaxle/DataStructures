#include <string>
#pragma once

using namespace std;

class Validation {

private:
	string input;
public:
	Validation();
	//~Validation();

	string checkFileName(string);
	string justFileName(string);

};//end class
