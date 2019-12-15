//
//  check_ips.c
//  Producto2
//
//  Created by Javier López (UOC) on 11/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#include "check_ips.h"

void get_ips_from_file(FILE *fp, char (ips)[4][20]) {
    char temp_ip[20];
    int ips_lenght;
    
    ips_lenght = 0;
    
    while (fgets(temp_ip, sizeof(temp_ip), fp)) {
        strcpy(ips[ips_lenght], temp_ip);
        ips_lenght++;
    }
}

char * exec_ip_ping(char file[200], char ip[20]) {
    char command[200], result[1000], content[1000] = "";

    strcpy(command, "");
    strcpy(command, "ping ");
    strcat(command, ip);
	strcat(command, " -n 1");
     
    FILE *f = _popen(command, "r");
    
    while (fgets(result, sizeof(result), f)) {
        strcat(content, result);
    }
    
    _pclose(f);
    
    return content;
}

void get_correct_ips(char test_file[200]) {
    // Read the file that contains the results and the correct are saved
    char content[5000] = "", * ip, c;
    char * is_ping;
    bool matched = false, has_received = false;
    int i;
    FILE* fp;
    
    i = 0;
    
    fp = fopen(test_file, "rb");
    
    while((c = getc(fp)) != EOF) {
        append(content, c);
        
        ip = extract_between(content, "Pinging ", " w");
        
        if (has_received && (strstr(content, "Received = 0")) == NULL) {
            printf("%s\n", ip);
            
            strcpy(content, "");
            strcpy(ip, "");
			has_received = false;
        }
        
        if (has_received && (strstr(content, "Received = 0")) != NULL) {
            strcpy(content, "");
            strcpy(ip, "");
			has_received = false;
        }

		if ((strstr(content, "Received = ") != NULL)) {
			has_received = true;
		}
        
        i++;
    }
}

int checkIps() {
    FILE* fp;
    char ips[4][20], ips_file[256], test_file[256], command[500] = "", content[1000] = "";
    int i;
    
    ask("Insert the path to the file that contains ips:\n", ips_file);
    ask("Insert the path to the file where save the results:\n", test_file);

    fp = fopen(ips_file, "rb");
    
    if (fp == NULL) {
        printf("File not found %s", ips_file);
        return 1;
    }
    
    get_ips_from_file(fp, ips);
    
    for (i = 0; i < 4; i++) {

        printf("%s", ips[i]);

        printf("\r");
        printf("\n");
    }

    // Exec pings to ips and write the results in test.txt
    printf("Testing IPs...");
    
    strcpy(command, "DEL ");
    strcat(command, test_file);
    system(command);
    strcpy(command, "type nul > ");
    strcat(command, test_file);
    system(command);
    
    for (i = 0; i < 4; i++) {
        strcat(content, exec_ip_ping(test_file, ips[i]));
        strcat(content, "\n\n");
    }
    
    FILE *f  = fopen(test_file, "w+");
    fputs(content, f);
    fclose(f);
    
    get_correct_ips(test_file);

    return(0);
}
