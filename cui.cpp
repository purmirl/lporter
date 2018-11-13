/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 *  Copyright 2018 PeTrA. All rights reserved.
 */

#include "cui.h"
#include <string>
#include <stdlib.h>

using namespace std;

Cui::Cui(){ 

}

Cui::~Cui(){

}

void Cui::printStartCui(){
	system("clear");
	printf("lporter 1.0 \n");
	printf("Copyright 2018 PeTrA. All rights reserved.\n\n");
	
	return;
}

void Cui::printHelpCui(){
	printf("\n");
	
	return;
}

string Cui::printCommandLine(){
	string result;
	printf("lporter >> ");
	getline(cin, result);

	return result;
}


