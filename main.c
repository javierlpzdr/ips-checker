#include <stdio.h>;

main()
{
	FILE* fp;
	char c, ips[5][15], temp_ip[15] = "";
	int i, x, ips_lenght;

	ips_lenght = 0;

	fp = fopen("/Users/javierlopez_uoc/Projects/Producto2/Producto2/ips.txt", "rb");

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
    
	for (i = 0; i <= ips_lenght; i++) {

		printf("%s", ips[i]);

		printf("\r");
		printf("\n");
	}

	printf("Testing IPs...");

	char *ip_prefix, *ip[25];
	ip_prefix = "ping ";
	char command[50];

	int z;

	z = strlen(ip);

	return(0);
}
