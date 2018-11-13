/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 * Copyright 2018 PeTrA. All rights reserved.
 */

#include <iostream>

#include "cui.h"

static Cui cui;

using namespace std;

int main(){
	cui.printStartCui();
	while(1){
		cui.printCommandLine();
	}			

	return 0;
}

