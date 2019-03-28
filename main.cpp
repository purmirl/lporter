/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 * Copyright 2018 PeTrA. All rights reserved.
 */

#include <iostream>
#include <string>

#include "cui.h"
#include "porter.h"

static Cui cui;
static Porter porter;

using namespace std;


int main(int argc, char* argv[]){
	cui.printStartCui();
	// cout << argv[1] << endl;
	
	// cout << "" << endl;
	cout << "System Messages >> " << endl;
	// cout << "----------------" << endl;
	porter.makeLogDirectory();
	cout << "----------------" << endl;
	cout << "" << endl;

	string str(argv[1]);
	porter.packetReader(str);
	while(1){
		cui.printCommandLine();
	}			

	return 0;
}

