#include<iostream>
#include<vector>
using namespace std;

// Each rule is broken down to a single dependency
class Rule {
	public:
		Rule(string& d, vector<string>& c);
		Rule(vector<string>& d, vector<string>& c);
		Rule(vector<string>& d, string& c);
		Rule(string& d, string& c);
		void init(vector<string>& d, vector<string>& c);
		Rule(){}

		//XXX
		//Need to only add if it doesn't already exist
		void addDep(string d) { dep.push_back(d); }
		void addCom(string d) { command.push_back(d); }

		void print() {
			cout << "printing rule dep=" << dep.size() << endl;
			for(unsigned int i=0; i < dep.size(); i++) {
				cout << "rule " << i << endl;
				cout << dep[i] << endl;
			}
		}
	protected:
		vector<string> dep;
		vector<string> command;
};
