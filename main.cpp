//Author: Poke J from Project Pokemon
//Title: Pokemon Space World Demo to PK2
//Purpose: To convert a dumped Pokemon from the Space World 98 Demo into a PK2 file
#include <iostream>
#include "File Manager.h"
#include "Pokemon.h"
#include "Security.h"
using namespace std;

int main(int argc, char* argv[]) {
	char pokeData[63] = { (char)0x01, (char)0x00, (char)0xFF }; //The Pokemon array with the fist 3 missing byts stores
	string pk2 = "MissingNo.";
	int index = 0; //stores the Pokemons species index number
	FileManager files; //Creats the file manager object
	DemoPokemon poke; //Creates teh poorly named Pokemon object
	Wrong valid; //Check various parts of the file to ensure that the file is valid
	valid.fileAdded(argc);
	valid.fileSize(argc, argv[1]);
	files.FileInput(argv[1], pokeData); //Opens the file
	index = valid.speciesCheck(pokeData);
	poke.appendData(pokeData, index); //Adds the last remaining bytes to the file
	pk2 = poke.species(pokeData, index);
	files.FileOutput(pokeData, pk2); //Outputs the file
	files.~FileManager(); //Deconstructs the file manager object
	poke.~DemoPokemon(); //Deconstructs the Pokemon object
	valid.~Wrong();

	return 0;
}