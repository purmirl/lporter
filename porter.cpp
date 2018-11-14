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

#include <string.h>

using namespace std;

Porter::Porter(){}

Porter::~Porter(){}

void Porter::packetReader(){
	int res;
	char deviceCharName[128];
	string deviceStringName = "";

	char errbuf[1024];
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
	
	// copy device string name to device char* name 
	strcpy(deviceCharName, deviceStringName.c_str());
	
	// if device name copy is failed....
	if(deviceCharName == NULL){
		fprintf(stderr, "device name recognition is failed. : %s\n", errbuf);
		exit(2);
	}
	
	if(pcap_lookupnet(deviceCharName, &net, &mask, errbuf) == -1){
		fprintf(stderr, "could not get netmask for device %s. : %s\n", deviceCharName, errbuf);
		net = 0;
		mask = 0;
		exit(2);
	}
	
	handle = pcap_open_live(deviceCharName, BUFSIZ, 1, 1000, errbuf);
	
	// if cannot the device....
	if(handle == NULL){
		fprintf(stderr, "could not open device %s : %s\n", deviceCharName, errbuf);
		exit(2);
	}
	
	while(1){
		res = pcap_next_ex(handle, &header, &packet);
		printf("%d bytes packet read.\n", header->len);
		if(res == 0){
			printf("error : packet reading is failed.\n");
			continue;
		}
	}	
}

void Porter::packetParser(){

}


