#include <stdio.h>
#include <string.h>

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

    // Exec pings to ips and write result in test.txt
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

    return(0);
}

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
    }
    
    system("ipconfig | find \"IP Address\" >> test ");
    
    return(0);
}

int compare_ips() {
    char ip_1[15] = "", ip_2[15] = "";
    char command[50] = "ping ";
    
    scanf("%s", ip_1);
    scanf("%s", ip_2);
    
    strcat(command, ip_1);
    system(command);
    
    strcpy(command, "ping ");
    strcat(command, ip_2);
    
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
