//
//  show_network_adapter.c
//  Producto2
//
//  Created by Javier López (UOC) on 11/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#include "show_network_adapter.h"

void save_adapter(char * path, char * adapter)
{
    char command[200];
    int i;
    
    i = 0;
    
    strcpy(command, "ifconfig ");
    strcat(command, adapter);
    strcat(command, " >> ");
    strcat(command, path);
    
    system(command);
}

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
    
    const char parts[3][50] = {
        "ip=",
        "mask=",
        "port="
    };
    
    adapter_info = get_adapter(path);
    
    for ( i=0; i <= 3; i++ ) {
        match = extract_between(adapter_info, parts[i], " ");
        if (match) {
            printf("%s", match);
        }
    }
    
    return(0);
}
