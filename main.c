#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//Función que permite leer cadenas con espacios en blanco en su interior

int leecad(char *cad, int n) {
    int i, c;
    c = getchar();
    
    if (c == EOF) {
        cad[0] = '\0';
        return 0;
    }
    
    if (c == '\n')
        i = 0;
    else {
        cad[0] = c;
        i = 1;
    }
    
    for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        cad[i] = c;
        cad[i] = '\0';
    
    if (c != '\n' && c != EOF)
        while ((c = getchar()) != '\n' && c != EOF);
    
    return 1;
};


int checkIps() {
    FILE* fp;
    char c, ips[5][15], temp_ip[15] = "", ips_file[200], test_file[200];
    int i, ips_lenght;

    ips_lenght = 0;
    
    printf("Insert the path to the file that contains ips:\n");
    scanf("%s", &ips_file);
    
    printf("Insert the path to the file where save the results:\n");
    scanf("%s", &test_file);
    
    fp = fopen(ips_file, "rb");
    
    // Get ips from a txt
    // TODO: Use fgets to get the lines directly
    while ((c = getc(fp)) != EOF) {
        if (c == '\r') continue;

        if (c == '\n') {
            strcpy(ips[ips_lenght], temp_ip);
            ips_lenght++;
            strcpy(ips[ips_lenght], "");
            strcpy(temp_ip, "");
            continue;
        }

        strncat(temp_ip, &c, 1);
    }

    strcpy(ips[ips_lenght], temp_ip);
    ips_lenght++;
    strcpy(ips[ips_lenght], "");
    strcpy(temp_ip, "");
    
    // Print ips in the terminal
    for (i = 0; i <= ips_lenght; i++) {

        printf("%s", ips[i]);

        printf("\r");
        printf("\n");
    }

    // Exec pings to ips and write the results in test.txt
    printf("Testing IPs...");

    char command[200];
    
    strcpy(command, "rm ");
    strcat(command, test_file);
    system(command);

    for (i = 0; i < ips_lenght; i++) {
        strcpy(command, "");
        strcpy(command, "ping -c2 ");
        strcat(command, ips[i]);
        strcat(command, " >> ");
        strcat(command, test_file);
        system(command);
    }
    
    // Read the file that contains the results and the correct are saved
    fp = fopen(test_file, "rb");
    
    char content[5000], results[4][15], ip[15];
    bool is_ping;
    
    content[5000];
    
    i = 0;
    
    while((c = getc(fp)) != EOF) {
        content[i] = c;
        
        is_ping = strstr("PING ", content) == "PING ";
        
        if (is_ping) {
            
            if (c == ' ') {
                is_ping = false
            } else {
                strcat(ip, c);
            }
        }
        
        if ((strstr(content, "packets received") == "packets received") && (strstr(content, "0 packets received")) != "0 packets received") {
            strcpy(results[i], ip);
        }
        
        i++;
    }

    return(0);
}

// Get the network adapter and the result is saved in a file
int show_network_adapter() {
    
    char adapter[50], command[200], path;
    
    char parts[3][50] = {
        "ip",
        "mask",
        "port"
    };
    
    int i;
    
    scanf("%s", &adapter);
    
    for (i = 0; i < parts; i++) {
        strcpy(command, "ipconfig ");
        strcat(command, adapter);
        strcat(command, " | find " );
        strcat(command, parts[i]);
        strcat(command, " >> ");
        strcat(command, path);
        
        system(command);
    }
    
    return(0);
}

// Compare two pings and show the fastest from both
int compare_ips() {
    char ip_1[15] = "", ip_2[15] = "";
    char command[50] = "ping -c1";
    char result_ping_1, speed_1, result_ping_2, speed_2;
    char c;
    
    char content_1, content_2;
    
    scanf("%s", ip_1);
    scanf("%s", ip_2);
    
    strcat(command, ip_1);
    
    FILE *f = popen(command, "r");
    
    if (f == NULL)
        return 1;
    
    while ((c = getc(f)) != NULL) {
        if (strstr(content_1, "time=") == "time=") {
            strcat(speed_1, c);
        } else {
            strcat(content_1, c);
        }
    }
    
    pclose(f);
    
    strcpy(command, "ping -c1");
    strcat(command, ip_2);
    
    FILE *f2 = popen(command, "r");
    
    if (f == NULL)
        return 1;
    
    while ((c = getc(f2)) != NULL) {
        if (strstr(content_2, "time=") == "time=") {
            strcat(speed_2, c);
        } else {
            strcat(content_2, c);
        }
    }
    
    pclose(f);
    
    if (speed_1 > speed_2) {
        printf("%s", ip_1);
    } else {
        printf("%s", ip_2);
    }
    
    return(0);
}

int main()
{
    int choice;

    // Create a menu
    do {
        printf("Menu\n\n");
        printf("1. Check ips\n");
        printf("2. Show newtwork adapter\n");
        printf("3. Compare ips\n");
        printf("4. Exit\n\n");
        printf("Select your choice:\n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Checking ips...\n\n");
                checkIps();
                break;
            case 2:
                printf("Showing network adapter...\n\n");
                show_newtwork_adapter();
                break;
            case 3:
                printf("Comparing two ips...\n\n");
                compare_ips();
                break;
            case 4:
                printf("goodbye\n");
                break;
            default:
                printf("wrong choice.Enter Again\n");
                break;
        }
    } while (choice != 4);
    
    return(0);
}
