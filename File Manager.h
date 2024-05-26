//Author: Poke J from Project Pokemon
//Title: Pokemon Space World Demo to PK2
//Purpose: To convert a dumped Pokemon from the Space World 98 Demo into a PK2 file
#pragma once
#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H
#include "File Manager.h";
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

//Manages the input file and the output of the new file
class FileManager {
public:
	FileManager();
	~FileManager();
	void FileInput(char* data, char p[]); //Loads the input file and checks to see if the file is appropiate before storing the data
	void FileOutput(char p[], string name); //Outputs the final Pokemon as a PK2
};
#endif // !FILE_MANAGER_H
