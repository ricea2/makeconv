#include<iostream>
#include<vector>
using namespace std;

// Each rule is broken down to a single dependency
class Rule {
	public:
		Rule(string t, string d, vector<string> command);
		Rule(){}
	protected:
		string target;
		string dep;
		int ad;
		vector<string> command;
};
