#include <iostream>
#include <vector>
#include "rule.h"

class RuleList {
	public:
		RuleList();
		//Functions for adding Rules
		//
		void addRule(string target, vector<string> deps, string command);
		void addRule(vector<string> target, vector<string> deps, vector<string> command);
		void addRule(vector<string> target, vector<string> deps, string command);
	protected:
		vector<Rule> ruleList;	
};
