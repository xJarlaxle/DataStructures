// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Hash.h"


int main(){

	Hash hashObj;
	int index;

	index = hashObj.hashFunc("accuracy");

	cout << index;
	cin.ignore();

    return 0;
}

