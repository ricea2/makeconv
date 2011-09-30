#include <iostream>
#include <vector>
#include <map>
#include "rule.h"
using namespace std;

class RuleList {
	public:
		RuleList();
		//Functions for adding Rules
		void addRule(string& target, vector<string>& deps, string& command);
		void addRule(vector<string> target, vector<string> deps, vector<string> command);
		void addRule(vector<string> target, vector<string> deps, string command);
		void print(string& target) {
			cout << "printing rulelist of size " << rules.size() << endl;
			rules[target]->print();
		}
	protected:
		map<string, Rule*> rules;	
};
