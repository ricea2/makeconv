#include <iostream>
#include "genMake.h"
class BsdMake: public GenMake {
	protected:
		void preProcess();
		void addRules();
	public:
		BsdMake(string s) : GenMake(s){};
		BsdMake() : GenMake(){};
};
