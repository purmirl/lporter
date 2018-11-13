/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 *  Copyright 2018 PeTrA. All rights reserved.
 */

#include <stdio.h>
#include <iostream>

using namespace std;

class Cui{
	public:
		Cui();
		~Cui();
		void printStartCui();
		void printHelpCui();
		string printCommandLine();		
};

