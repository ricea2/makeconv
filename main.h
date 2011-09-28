#include "bsdMake.h"
#include<iostream>
#include<unistd.h>
#include<getopt.h>
#include<string.h>

// Structure to hold command line arguments
// XXX----->>>>> _t represents typedef
struct globalArgs_t {
	char *makePath; 	// -m Option
	int verbose;		// -v Option
	char *makeType;	// -t Option
} globalArgs;

static const char *optString = "m:vt:h?";

void usage();
