//Author: Poke J from Project Pokemon
//Title: Pokemon Space World Demo to PK2
//Purpose: To convert a dumped Pokemon from the Space World 98 Demo into a PK2 file
#include "Pokemon.h"

DemoPokemon::DemoPokemon() {};

DemoPokemon::~DemoPokemon() {};

void DemoPokemon::appendData(char p[], int index) {
	int j = 0; //Needed to tranverse the array to append the Pokemon data.  It's shorter then the Pokemon array
	int ot = 0; //determins if the OT is the defualt or "?" if ID is 00000
	int id1 = (int)p[9]; //sums up the total of the Pokemon OT ID
	int id2 = (int)p[10];
	int idF = id1 + id2;
	int N = 10;

	p[4] = (char)0x00; //Sets the hold item to none.

	if (id1 <= -1) {}  //determines if the Pokemons Trainer ID is 00000
	else {
		if (id2 <= -1) {}
		else {
			if (idF == 0)
				ot = 1;
		}
	}

	for (int i = 51; i < 57; i++) { //Adds the OT data to the Pokemon array.
		p[i] = endString[ot][j];
		j++;
	}

	j = 0;

	for (int i = 57; i < 63; i++) { //Adds the Nickname data to the Pokemon array.
		p[i] = pokeName[index - 1][j];
		j++;
	}
};

string DemoPokemon::species(char p[], int index) {
	int temp = index - 1;
	string name = fileName[temp];

	//Remaps the Pokemon species to a known species if it exsists
		if (index == 161)
			p[3] = (char)0xA3;
		else if (index == 162)
			p[3] = (char)0xA4;
		else if (index == 163)
			p[3] = (char)0xB3;
		else if (index == 164)
			p[3] = (char)0xB4;
		else if (index == 165)
			p[3] = (char)0xB5;
		else if (index == 166)
			p[3] = (char)0x25;
		else if (index == 167)
			p[3] = (char)0x72;
		else if (index == 168)
			p[3] = (char)0x72;
		else if (index == 169)
			p[3] = (char)0xE2;
		else if (index == 170)
			p[3] = (char)0xD3;
		else if (index == 171)
			p[3] = (char)0xD3;
		else if (index == 175)
			p[3] = (char)0xC3;
		else if (index == 176)
			p[3] = (char)0xB1;
		else if (index == 177)
			p[3] = (char)0xB2;
		else if (index == 178)
			p[3] = (char)0x76;
		else if (index == 179)
			p[3] = (char)0xB7;
		else if (index == 183)
			p[3] = (char)0xA9;
		else if (index == 184)
			p[3] = (char)0x2E;
		else if (index == 185)
			p[3] = (char)0xA7;
		else if (index == 186)
			p[3] = (char)0xA8;
		else if (index == 187)
			p[3] = (char)0xE3;
		else if (index == 188)
			p[3] = (char)0x84;
		else if (index == 189)
			p[3] = (char)0x54;
		else if (index == 190)
			p[3] = (char)0xC0;
		else if (index == 191)
			p[3] = (char)0xE7;
		else if (index == 192)
			p[3] = (char)0xE8;
		else if (index == 193)
			p[3] = (char)0xCB;
		else if (index == 194)
			p[3] = (char)0xCB;
		else if (index == 195)
			p[3] = (char)0xEB;
		else if (index == 196)
			p[3] = (char)0x34;
		else if (index == 199)
			p[3] = (char)0xBA;
		else if (index == 200)
			p[3] = (char)0xC7;
		else if (index == 202)
			p[3] = (char)0xA5;
		else if (index == 203)
			p[3] = (char)0xA6;
		else if (index == 204)
			p[3] = (char)0x4D;
		else if (index == 205)
			p[3] = (char)0xC4;
		else if (index == 206)
			p[3] = (char)0xC5;
		else if (index == 208)
			p[3] = (char)0x58;
		else if (index == 209)
			p[3] = (char)0xDF;
		else if (index == 210)
			p[3] = (char)0xE0;
		else if (index == 211)
			p[3] = (char)0xEC;
		else if (index == 212)
			p[3] = (char)0xED;
		else if (index == 213)
			p[3] = (char)0x3A;
		else if (index == 214)
			p[3] = (char)0xBB;
		else if (index == 215)
			p[3] = (char)0xBC;
		else if (index == 216)
			p[3] = (char)0xBD;
		else if (index == 217)
			p[3] = (char)0x7A;
		else if (index == 218)
			p[3] = (char)0xEE;
		else if (index == 219)
			p[3] = (char)0xEF;
		else if (index == 220)
			p[3] = (char)0xF0;
		else if (index == 221)
			p[3] = (char)0xB6;
		else if (index == 222)
			p[3] = (char)0x47;
		else if (index == 223)
			p[3] = (char)0xF1;
		else if (index == 228)
			p[3] = (char)0x53;
		else if (index == 231)
			p[3] = (char)0xC6;
		else if (index == 232)
			p[3] = (char)0xF2;
		else if (index == 233)
			p[3] = (char)0xD4;
		else if (index == 234)
			p[3] = (char)0x7F;
		else if (index == 235)
			p[3] = (char)0xE4;
		else if (index == 236)
			p[3] = (char)0xE5;
		else if (index == 239)
			p[3] = (char)0xE9;
		else if (index == 240)
			p[3] = (char)0x6C;
		else if (index == 241)
			p[3] = (char)0xD0;
		else if (index == 242)
			p[3] = (char)0xE6;
		else if (index == 246)
			p[3] = (char)0xD7;
		else if (index == 247)
			p[3] = (char)0xFA;
		else if (index == 248)
			p[3] = (char)0xAF;
		else if (index == 249)
			p[3] = (char)0xD1;
		else if (index == 250)
			p[3] = (char)0xBE;
		else if (index == 251)
			p[3] = (char)0x85;
		else;
	p[1] = p[3]; //Sets the Pokemon species into the another part of the Pokemon array.

	return name;
};