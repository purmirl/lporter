/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 * Copyright 2018 PeTrA. All rights reserved.
 */

#include "cui.h"
#include "porter.h"
#include "option.h"

#include <iostream>
#include <string>
#include <string.h>

static Cui cui;
static Porter porter;
static Option option;

using namespace std;


int main(int argc, char* argv[]){
	string optionValue(argv[1]);
	if(optionValue.compare(option.INTERFACE_OPTION) == 0){
		option.setInterface(1, argv[2]);
	}else{
		cout << "put the option.." << endl;
	}
	
	cui.printStartCui();
	// cout << argv[1] << endl;
	
	// cout << "" << endl;
	cout << "System Messages >> " << endl;
	// cout << "----------------" << endl;
	porter.makeLogDirectory();
	cout << "----------------" << endl;
	cout << "" << endl;

	// string str(argv[1]);
	// porter.packetReader(str);
	porter.packetReader(option.getInterfaceName());
	while(1){
		cui.printCommandLine();
	}			

	return 0;
}

