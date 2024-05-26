#pragma once
#ifndef SECURITY_H
#define SECURITY_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

class Wrong {
public:
	Wrong();
	~Wrong();
	void fileSize(int argc, char* data); //Checks file size
	int speciesCheck(char p[]); //Makes sure that a valid specie has been added
	void fileAdded(int argc); //makes only one file has been added
};
#endif // !SECURITY_H
