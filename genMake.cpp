#include "genMake.h"
#include "global.h"

// Print dependency list
void GenMake::printDeps() { 
	if(globalArgs.verbose)
		cout << "Printing Dependencies" << endl;

	string line;
	if(makeFile.is_open()) {
		while(makeFile.good()) {
			getline(makeFile, line);
			cout << line << endl; 
		}
	}
}

// Finds all rules and adds them to list
void GenMake::addRules() {
}

// Open the Makefile
bool GenMake::open(string fname) {
	makeFile.open(fname.c_str()); 
	return makeFile.is_open();
}
