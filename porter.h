/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 *  Copyright 2018 PeTrA. All rights reserved.
 */

#include <iostream>
#include <netinet/in.h>
#include <netinet/ether.h>
#include <arpa/inet.h>
#include <pcap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdint.h>

using namespace std;

class Porter{
	public:
		Porter();
		~Porter();
		void packetReader(string _device);
		void packetParser(const u_char* packet);
		void makeLogDirectory();
};
