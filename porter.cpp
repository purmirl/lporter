/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 *  Copyright 2018 PeTrA. All rights reserved.
 */

#include "porter.h"
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

Porter::Porter(){}

Porter::~Porter(){}

void Porter::packetReader(){
	char deviceCharName[128];
	string deviceStringName = "";

	char* errbuf[1024];
	const u_char* packet;
	pcap_t* handle;
	bpf_u_int32 mask;
	bpf_u_int32 net;
	struct bpf_program fp;
	struct pcap_pkthdr* header;
	
	// if device name is empty....
	if(!deviceStringName.compare("")){
		cout << "error : input the device name. " << endl;
		exit(2);
	}
	
}

void Porter::packetParser(){

}


