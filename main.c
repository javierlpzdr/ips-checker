#include <stdio.h>
#include <string.h>
#include "lib/check_ips.h"
#include "lib/show_network_adapter.h"
#include "lib/compare_ips.h"

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
                show_network_adapter();
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
