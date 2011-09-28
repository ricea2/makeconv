#include <iostream>
#include <fstream>
#include <vector>
#include "ruleList.h"
using namespace std;

// Define an abstract base class to be used for
// generic makefile definitions
// ex: GNU make, BSD make, and nmake
class GenMake {
	protected:
		ifstream makeFile;
		RuleList rules;

		//----Make into virtual methods to be overwritten---
		// Preform Macro substitutions
		virtual void preProcess()=0;
		
		virtual void addRules()=0;
		//----------------------------

	public:
		GenMake(string fname) { makeFile.open(fname.c_str()); }
		GenMake(){}
		bool open(string fname); 
		void printDeps();
};
