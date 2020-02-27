#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "show_network_adapter.h"

// Save the adapter config from a specific one

void save_adapter(char* path, char* adapter)
{
	char command[200];
	int i;

	i = 0;

	copy(command, "netsh interface ip show config name=\"");
	concat(command, adapter);
	concat(command, "\" > ");
	concat(command, path);
	system(command);
}



// Get the adapter config from a specific one

void get_adapter(char* path) {
	int c;
	FILE* file;
	file = NULL;

	fopen_s(&file, path, "r");
	
	if (file != NULL) {
		while ((c = getc(file)) != EOF)
			putchar(c);
		fclose(file);
	}
}



// Get the network adapter and the result is saved in a file

int show_network_adapter() {
	char adapter[256], path[256];
	int i;

	i = 0;

	ask("Which adapter:\n", adapter);
	ask("Where do you want save the config:\n", path);

	save_adapter(path, adapter);

	get_adapter(path);

	return 1;
}

