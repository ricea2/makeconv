#include "ruleList.h"
#include "global.h"

// Creates default rules for makefile type
RuleList::RuleList() {
}
void RuleList::addRule(string& target, vector<string>& deps, string& command) {
	if(globalArgs.verbose) {
		cout << "Adding rule\n   " << target << ": ";
		for(unsigned int i =0; i< deps.size(); i++)
			cout << deps[i] << " ";
		cout << endl;
	}
	if(rules.find(target) == rules.end()) {
		if(globalArgs.verbose)
			cout << "Creating New Dependency" << endl;

		rules[target] = new Rule(deps, command);
		cout << "printing added rule" << endl;
		rules[target]->print();
	} else {
		if(globalArgs.verbose)
			cout << "Adding to Dependency" << endl;
		for(unsigned int i=0; i<deps.size(); i++)
			rules[target]->addDep(deps[i]);
	}
}
void RuleList::addRule(vector<string> target, vector<string> deps, vector<string> command){
	for(unsigned int i=0; i<target.size(); i++) {
		rules[target[i]] = new Rule(deps, command);
	}
}
void RuleList::addRule(vector<string> target, vector<string> deps, string command){
	for(unsigned int i=0; i<target.size(); i++) {
		rules[target[i]] = new Rule(deps, command);
	}
}
