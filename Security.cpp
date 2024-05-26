#include "Security.h"

Wrong::Wrong() {};

Wrong::~Wrong() {};

void Wrong::fileSize(int argc, char* data) {
	int size = 0; //Stores the size of the inputed file

	if (argc != 2) { //Checks to see to see if there is a file
		cout << "Error: File not found.  Press Enter to exit." << endl;
		cout << "How to use:" << endl; //Tutorial
		cout << "-Dump Pokemon from the Space World 98 by:" << endl;
		cout << "--Load the game." << endl;
		cout << "--Put the Pokemon you want to dump in the first slot of the party." << endl;
		cout << "--In the emulator click on Tool -> Debug -> Memory Viewer then click the save option." << endl;
		cout << "--In the Address box input 0000D6B2 and in the Size box input 30.  Then click OK." << endl;
		cout << "--Save the .dmp file somewhere that you can find it." << endl;
		cout << "-Drag and drop the .dmp file you just made onto this application." << endl;
		cout << "-The file called Dumped Pokemon will be created and now can be opened in PKHeX." << endl;
		cin.get();
		exit(1);
	};

	ifstream pokeDump(data, ios::in | ios::binary); //Opens the file
	if (!pokeDump) { //If file cannot be found
		cout << "Error: Cannot open this file. Press Enter to exit." << endl;
		cin.get();
		exit(1);
	};

	//Gets and stores the size of the inputted file
	pokeDump.seekg(0, ios::end);
	size = (int)pokeDump.tellg();

	if (size > 48) { //Ends the program if the file is too large.
		cout << "Error: File is too big. Press Enter to exit." << endl;
		cin.get();
		exit(1);
	}
	else if (size < 48) { //Ends the program if the file is too small.
		cout << "Error: File is too small. Press Enter to exit." << endl;
		cin.get();
		exit(1);
	}
	else;
};

int Wrong::speciesCheck(char p[]) {
	int index = (int)p[3];
	if (index < 0)
		index = 256 + index;

	if (index > 251) {
		cout << "Error: The Pokemon Pokedex number is over 251. Press Enter to exit." << endl;
		cin.get();
		exit(1);
	}
	return index;
};
//Ensures that a file has been added
void Wrong::fileAdded(int argc) {
	if (argc < 2) { //If no file has been added
		cout << "Error: No file has been found. Press Enter to exit." << endl;
		cout << "How to use:" << endl; //Tutorial
		cout << "-Dump Pokemon from the Space World 98 by:" << endl;
		cout << "--Load the game." << endl;
		cout << "--Put the Pokemon you want to dump in the first slot of the party." << endl;
		cout << "--In the emulator click on Tool -> Debug -> Memory Viewer then click the save option." << endl;
		cout << "--In the Address box input 0000D6B2 and in the Size box input 30.  Then click OK." << endl;
		cout << "--Save the .dmp file somewhere that you can find it." << endl;
		cout << "-Drag and drop the .dmp file you just made onto this application." << endl;
		cout << "-The file called Dumped Pokemon will be created and now can be opened in PKHeX." << endl;
		cin.get();
		exit(1);
	}
	else if (argc > 2) { //If more than one file has been added
		cout << "Error: Too many files added. Press Enter to exit." << endl;
		cout << "Only add one file at a time." << endl;
		cin.get();
		exit(1);
	}
	else; //Only one file has been added so the application can run properly
};