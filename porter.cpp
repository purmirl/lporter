/**
 * lporter project.
 * Simple IDS for CentOS System.
 * ------
 *  Copyright 2018 PeTrA. All rights reserved.
 */

#include "porter.h"

#include <netinet/in.h>
#include <netinet/ether.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#include <arpa/inet.h>
#include <pcap/pcap.h>

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdint.h>

#include <string.h>
#include <ctime>

using namespace std;

Porter::Porter(){
	init();
}

Porter::~Porter(){}

void Porter::init(){
	ether_type = "";
}

void Porter::packetReader(string _device){
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
	
	deviceStringName = _device;
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
	
	// cout << deviceCharName << endl;
	
	if(pcap_lookupnet(deviceCharName, &net, &mask, errbuf) == -1){
		fprintf(stderr, "could not get netmask for device %s. : %s\n"
			, deviceCharName, errbuf);
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
		// printf("%d bytes packet read.\n", header->len);
		if(res == 0){
			//printf("%d bytes packet read.\n", header->len);
			continue;
		}else if(res == -1){
			printf("error : packet reading if failed.\n");
			continue;
		}
		printf("%d bytes packet read.\n", header->len);
		packetParser(packet);
	}
	return;	
}

/**
 * ETHERTYPE : IP, ARP, PUP, Trail, Ntrailer
 *  - ETHERTYPE_IP
 *  - ETHERTYPE_ARP
 *  - ETHERTYPE_PUP
 *  - ETHERTYPE_TRAIL
 *  - ETHERTYPE_NTRAILER
 */
void Porter::packetParser(const u_char* _packet){
	const struct ether_header* ethernetHeader;
	const struct ip* ipHeader;
	const struct tcphdr* tcpHeader;
	
	ethernetHeader = (struct ether_header*)_packet;
	// cout << ntohs(ethernetHeader->ether_type) << endl;
	if(ntohs(ethernetHeader->ether_type) == ETHERTYPE_IP){
		cout << "ether type : ip" << endl;
		ether_type = "ETHERTYPE_IP";
	}else if(ntohs(ethernetHeader->ether_type) == ETHERTYPE_ARP){
		cout << "ether type : arp" << endl;
		ether_type = "ETHERTYPE_ARP";
	}else if(ntohs(ethernetHeader->ether_type) == ETHERTYPE_PUP){
		cout << "ether type : pup" << endl;
		ether_type = "ETHERTYPE_PUP";
	}else if(ntohs(ethernetHeader->ether_type) == ETHERTYPE_TRAIL){
		cout << "ether type : trail" << endl;
		ether_type = "ETHERTYPE_TRAIL";	
	}else if(ntohs(ethernetHeader->ether_type) == ETHERTYPE_NTRAILER){
		cout << "ether_type : ntrailer" << endl;
		ether_type = "ETHERTYPE_NTRAILER";
	}
}

void Porter::makeLogDirectory(){
	time_t t_time;
	struct tm *s_time;
	char buffer[1024];

	time(&t_time);
	s_time = localtime(&t_time);
	strftime(buffer, 1024, "%Y%m%d", s_time);
	
	// printf(buffer);

	system("mkdir ./log");
	return;
}


