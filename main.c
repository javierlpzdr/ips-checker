#include <stdio.h>;

main()
{
	FILE* fp;
	char c, ips[5];
	int i, x, ips_lenght;

	ips_lenght = 0;
	ips[0] = "";

	fp = fopen("./ips.txt", "rb");

	while ((c = getc(fp)) != EOF) {
		if (c == '\n') continue;

		if (c == '\r') {
			ips_lenght++;
			ips[ips_lenght] = "";
			continue;
		}

		ips[ips_lenght] = malloc(strlen(ips[ips_lenght]) + 1);
		ips[ips_lenght] += c;
	}

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