#include "main.h"
#define MAIN_CPP
#include "global.h"

int main(int argc, char* argv[]) {
	int opt=0;
	if(argc <= 1) {
		usage();
		exit(-1);
	}

	GenMake *mfile=NULL;

	//Initialize global options
	globalArgs.makePath=NULL;
	globalArgs.verbose=0;
	globalArgs.makeType=NULL;

	opt = getopt(argc, argv, optString);
	while(opt != -1) {
		switch(opt) {
			case 'm':
				globalArgs.makePath = optarg;
				break;
			case 'v':
				globalArgs.verbose++;
				break;
			case 't':
				globalArgs.makeType = optarg;
				break;
			case 'h':
			case '?':
				usage();
				break;
			default:
				break;
		}
		opt = getopt(argc, argv, optString);
	}

	// Set the Makefile Type
	if(!strcmp(globalArgs.makeType,"bsd")) {
		mfile = new BsdMake;
		if(globalArgs.verbose)
			cout << "Assuming BSD Makefile" << endl;
	} else {
		cout << "ERROR: must declare makefile type" << endl;
		usage();
		exit(-1);
	}

	// Open specified Makefile
	if(!mfile->open(globalArgs.makePath)) {
		cout << "ERROR: Could not open " << globalArgs.makePath << endl;
		usage();
		exit(-1);
	} else if(globalArgs.verbose)
		cout << "Opened " << globalArgs.makePath << endl;

	mfile->printDeps();
	return 0;
}

void usage() {
	cout << "usage ./" << endl;
	cout << "Makefile Converter" << endl;
	cout << "\tConverts makefiles into common XML format" << endl;
}
