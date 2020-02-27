#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "terminal.h"
#include "check_ips.h"

// Ping to ips
void exec_ip_ping(char file[200], char ip[20], char content[10000]) {
	char command[200], result[10000];
	FILE* f;
	copy(command, "");
	copy(command, "ping ");
	concat(command, ip);
	concat(command," -n 1");
	
	f = _popen(command, "r");

	while (fgets(result, sizeof(result), f) != 0) {
		concat(content, result);
	}

	_pclose(f);
}

// Get all the ips from a file
void get_ips_from_file(FILE *fp, char ips[4][20]) {
	char temp_ip[20];
	int ips_lenght;
	ips_lenght = 0;

	while (fgets(temp_ip, sizeof(temp_ip), fp)) {
		copy(ips[ips_lenght], temp_ip);
		ips_lenght++;
	}
}

// Print only the ips that works

void get_correct_ips(char test_file[200]) {
	// Read the file that contains the results and the correct are saved
	char content[5000] = "", * ip, c;
	bool matched, has_received;

	matched = false;
	has_received = false;


	int i;
	FILE *fp = NULL;
	
	i = 0;

	fopen_s(&fp, test_file, "r");

	if (fp == NULL) {
		printf("Test file was not found");
		return;
	}

	while ((c = getc(fp)) != EOF) {
		append(content, c);

		ip = extract_between(content, "Pinging ", " w");

		if (has_received && (strstr(content, "Received = 0")) == NULL) {
			printf("%s\n", ip);
			copy(content, "");
			copy(ip, "");
			has_received = false;
		}

		if (has_received && (strstr(content, "Received = 0")) != NULL) {
			copy(content, "");
			copy(ip, "");
			has_received = false;
		}

		if ((strstr(content, "Received = ") != NULL)) {
			has_received = true;
		}

		i++;
	}
}

// Ping to ips from a file and show the ones that works
int checkIps() {

	FILE* fp = NULL;
	char ips[4][20], ips_file[256], test_file[256], command[500] = "", content[10000] = "";
	int i;

	i = 0;
	
	ask("Insert the path to the file that contains ips:\n", ips_file);
	ask("Insert the path to the file where save the results:\n", test_file);

	fopen_s(&fp, ips_file, "r");

	if (fp == NULL) {
		printf("File not found %s", ips_file);
		return 1;
	}

	get_ips_from_file(fp, ips);

	fclose(fp);
	
	for (i = 0; i < 4; i++) {
		printf("%s", ips[i]);
		printf("\r");
		printf("\n");
	}

	//Exec pings to ips and write the results in test.txt
	printf("Testing IPs...\n");

	copy(command, "DEL ");
	concat(command, test_file);
	system(command);


	for (i = 0; i < 4; i++) {
		exec_ip_ping(test_file, ips[i], content);
		concat(content, "\n\n");
	}

	FILE* f = NULL;

	fopen_s(&f, test_file, "w+");

	if (f == NULL) {
		printf("File was not found");
	}

	fputs(content, f);

	fclose(f);

	get_correct_ips(test_file);


	return 0;
}
