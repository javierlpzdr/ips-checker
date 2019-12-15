//
//  show_network_adapter.c
//  Producto2
//
//  Created by Javier López (UOC) on 11/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#include "show_network_adapter.h"

// Save the adapter config from a specific one
void save_adapter(char * path, char * adapter)
{
    char command[200];
    int i;
    
    i = 0;
    
    strcpy(command, "netsh interface ip show config name=\"");
    strcat(command, adapter);
    strcat(command, "\" > ");
    strcat(command, path);
    
    system(command);
}

// Get the adapter config from a specific one
char * get_adapter(char * path) {
    FILE * f = fopen (path, "rb");
    char * buffer;
    int length;
    
    if (f)
    {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = malloc (length);
      if (buffer)
      {
        fread (buffer, 1, length, f);
      }
      fclose (f);
    }
    
    return buffer;
}

// Get the network adapter and the result is saved in a file
int show_network_adapter() {
    
    char adapter[200] = "", path[200] = "", * adapter_info, * match;
    int i;
    
    ask("Nombre del adaptador:\n", adapter);
    ask("En que archivo:\n", path);
    
    save_adapter(path, adapter);
    
    adapter_info = get_adapter(path);
    
	printf("%s", adapter_info);
    
    return(0);
}
