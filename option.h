/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 *  Copyright 2019 PeTrA. All rights reserved.
 */

#include <iostream>
#include <string>

using namespace std;

class Option{
	public:
		Option();
		~Option();
	
	private:
		void init();
		int isInterface;
		string INTERFACE_NAME;
	 			
};
