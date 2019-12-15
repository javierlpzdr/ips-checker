//
//  compare_ips.c
//  Producto2
//
//  Created by Javier López (UOC) on 11/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#include "compare_ips.h"

float get_ping_time(char ip[20]) {
    char command[50] = "ping -c1 ", * ret, ping_result[200];
    char * search_result;
    
    strcat(command, ip);
    
    FILE *f = popen(command, "r");
    
    if (f == NULL)
        return 1;
    
    while (fgets(ping_result, sizeof(ping_result), f)) {
        if (search(ping_result, "time=")) {
            
            char * p1= "time=";
            char * p2= " ms";
            
            const char *i1 = strstr(ping_result, p1);
            if(i1 != NULL)
            {
              const size_t pl1 = strlen(p1);
              const char *i2 = strstr(i1 + pl1, p2);
              if(p2 != NULL)
              {
               /* Found both markers, extract text. */
               const size_t mlen = i2 - (i1 + pl1);
               ret = malloc(mlen + 1);
               if(ret != NULL)
               {
                 memcpy(ret, i1 + pl1, mlen);
                 ret[mlen] = '\0';
               }
              }
            }
        }
    }
    	
    pclose(f);
    
    float time = strtof(ret, NULL);
    printf("%f\n", time);
    return time;
}

// Compare two pings and show the fastest from both
int compare_ips() {
    char ip_1[20] = "", ip_2[20] = "";
    float speed_1, speed_2;
    
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
    
    if (speed_1 == 0 || speed_2 == 0) {
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
