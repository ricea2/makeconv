#include "rule.h"

Rule::Rule(string t, string d, vector<string> c) {
	target = t;
	dep = d;
	command = c;
}

