//
//  compare_ips.c
//  Producto2
//
//  Created by Javier López (UOC) on 11/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#include "compare_ips.h"

float get_ping_time(char ip[20]) {
    char command[50] = "ping ", * ret, ping_result[200];
    ret = "0";
    
    strcat(command, ip);
    
    FILE *f = _popen(command, "r");
    
    if (f == NULL)
        return 1;
    
    while (fgets(ping_result, sizeof(ping_result), f)) {
        if (search(ping_result, "Average = ")) {
            ret = extract_between(ping_result, "Average = ", "ms");
        }
    }
    	
    _pclose(f);
    
	float time = 0;
	time = atoi(ret);
    
    printf("%f\n", time);
    return time;
}

// Compare two pings and show the fastest from both
int compare_ips() {
    char ip_1[20] = "", ip_2[20] = "";
    float speed_1 = 0.0, speed_2 = 0.0;
    
    ask("What's the first ip:\n", &ip_1);
    ask("What's the second ip:\n", &ip_2);
    
    printf("testing the connection with...\n");
    printf("%s\n", ip_1);
    
    speed_1 = get_ping_time(ip_1);
    
    printf("testing the connection with...\n");
    printf("%s\n", ip_2);
    
    speed_2 = get_ping_time(ip_2);
    
    printf("The result of ip %s is %f\n", ip_1, speed_1);
    printf("The result of ip %s is %f\n", ip_2, speed_2);
    
    if (speed_1 == 0 || speed_2 == 0) {
        printf("A error succed\n");
    } else {
        printf("The fastest ip is...\n");
        
        if (is_bigger(speed_1, speed_2)) {
            printf("%s\n", ip_1);
        } else {
            printf("%s\n", ip_2);
        }
    }
    
    return(0);
}
