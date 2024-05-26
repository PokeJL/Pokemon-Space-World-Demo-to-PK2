//Author: Poke J from Project Pokemon
//Title: Pokemon Space World Demo to PK2
//Purpose: To convert a dumped Pokemon from the Space World 98 Demo into a PK2 file
#include "File Manager.h"

FileManager::FileManager() {};

FileManager::~FileManager() {};

//Reads and stores the dumped data into the Pokemon array
void FileManager::FileInput(char* data, char p[]) {

	ifstream pokeDump(data, ios::in | ios::binary); //Opens the file
	if (!pokeDump) { //If file cannot be found
		cout << "Error: Cannot open this file. Press Enter to exit." << endl;
		cin.get();
		exit(1);
	};

	for (int i = 3; !pokeDump.eof(); i++) { //Starts at element 3 in the array as to not overwrite the first 3 bytes
		pokeDump.get(p[i]); //Stores one byte of the file in the i element of the array
	};

	pokeDump.close();
};

//Outputs the Pokemon array as a PK2 file
void FileManager::FileOutput(char p[], string name) {
	string opName = name; //"Dumped Pokemon"; //File name until further update
	bool loop = false; //Used to keep loop going for the Output files name

	if (p[25] == (char)0xAA) {
		if (p[24] == (char)0x2A || p[24] == (char)0x3A || p[24] == (char)0x6A || p[24] == (char)0x7A || p[24] == (char)0xAA || p[24] == (char)0xBA || p[24] == (char)0xEA || p[24] == (char)0xFA)
			opName = opName + " Shiny"; //If the pokemon is shiny then a star is added to its name \u2605
	}

	while (loop == false) { //Will loop until a unused file name is made
		ifstream PFO(opName + ".pk2"); //Attempts to open a file with the current name
		if (!PFO) { //Checks to see if the file exists
			ofstream outfile(opName + ".pk2", ios::binary); //If file does not exist creat a new file with the current name that has been made output as a binary file
			for (int m = 0; m < 63; m++) { 
				outfile << p[m]; //Outputs the Pokemon array
			}
			loop = true; //Sets loop to true to close the loop
		}
		else { //If there is a file with the current name a + will be added to the end of the name until an unused file name is created
			opName = opName + "+";
		}
	}
};