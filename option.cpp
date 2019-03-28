/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 *  Copyright 2019 PeTrA. All rights reserved.
 */

#include "option.h"

#include <iostream>

using namespace std;

Option::Option(){
	init();
}

Option::~Option(){}

void Option::void init(){
	INTERFACE_OPTION = "-i";
	isInterface = 0;
	INTERFACE_NAME = "";
	
}

void Option::setInterface(int _isInterface, string _INTERFACE_NAME){
	isInterface = _isInterface;
	INTERFACE_NAME = _INTERFACE_NAME;
}

int Option::getIsInterface(){
	return isInterface;
}

string Option::getInterface(){
	return INTERFACE_NAME;	
}



