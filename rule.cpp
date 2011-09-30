#include "rule.h"

Rule::Rule(string& d, vector<string>& c) {
	vector<string> v;
	v.push_back(d);
	command = c;
	init(v, c);
}

Rule::Rule(string& d, string& c) {
	vector<string> v;
	v.push_back(c);

	vector<string> r;
	r.push_back(d);
	init(r, v);
}

Rule::Rule(vector<string>& d, string& c) {
	vector<string> v;
	v.push_back(c);
	init(d, v);
}
Rule::Rule(vector<string>& d, vector<string>& c) {
	init(d,c);
}

void Rule::init(vector<string>& d, vector<string>& c) {
	dep = d;
	command = c;
}

