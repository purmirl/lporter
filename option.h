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
		string INTERFACE_OPTION;
		
		void setInterface(int _isInterface, string _INTERFACE_NAME);
		int getIsInterface();
		string getInterfaceName();
	
	private:
		void init();
		int isInterface;
		string INTERFACE_NAME;		
};
