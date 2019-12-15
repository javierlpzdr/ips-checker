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

void print_ips(char (*ips)[4][20]) {
    int i;
    i = 0;
    
    int size;
    
    size = sizeof(ips);
    
    // Print ips in the terminal
    for (i = 0; i < 4; i++) {

        printf("%s", ips[i]);

        printf("\r");
        printf("\n");
    }
}

void exec_ip_pings(char file[200], char (ips)[4][20]) {
    char command[200];
    int i;
    
    strcpy(command, "rm ");
    strcat(command, file);
    system(command);

    for (i = 0; i < sizeof(ips); i++) {
        strcpy(command, "");
        strcpy(command, "ping -c2 ");
        strcat(command, ips[i]);
        strcat(command, " >> ");
        strcat(command, file);
        system(command);
    }
}

void get_correct_ips(char test_file[200]) {
    // Read the file that contains the results and the correct are saved
    char content[5000], results[4][15], ip[15], c;
    bool is_ping;
    int i;
    FILE* fp;
    
    i = 0;
    
    fp = fopen(test_file, "rb");
    
    content[5000];
    
    while((c = getc(fp)) != EOF) {
        content[i] = c;
        
        is_ping = strstr("PING ", content) == "PING ";
        
        if (is_ping) {
            
            if (c == ' ') {
                is_ping = false;
            } else {
                strcat(ip, c);
            }
        }
        
        if ((strstr(content, "packets received") == "packets received") && (strstr(content, "0 packets received")) != "0 packets received") {
            strcpy(results[i], ip);
        }
        
        i++;
    }
}

int checkIps() {
    FILE* fp;
    char ips[4][20], ips_file[256], test_file[256];
    
    ask("Insert the path to the file that contains ips:\n", &ips_file);
    ask("Insert the path to the file where save the results:\n", &test_file);

    fp = fopen(ips_file, "rb");
    
    if (fp == NULL) {
        printf("File not found %s", ips_file);
        return 1;
    }
    
    get_ips_from_file(fp, ips);
    print_ips(ips);

    // Exec pings to ips and write the results in test.txt
    printf("Testing IPs...");
    
    exec_ip_pings(test_file, ips);
    get_correct_ips(test_file);

    return(0);
}
