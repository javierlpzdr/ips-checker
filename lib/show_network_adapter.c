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

char * get_adpater(path) {
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
    
    char adapter[50], path[200], * adapter_info;
    
    ask("Nombre del adaptador:\n", &adapter);
    ask("En que archivo:\n", &path);
    
    save_adapter(path, adapter);
    
    const char parts[3][50] = {
        "ip",
        "mask",
        "port"
    };
    
    adapter_info = get_adapter(path);
    
    char * ret;
    char * p1= "time=";
    char * p2= " ms";
    
    const char *i1 = strstr(adapter_info, p1);
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
    
    return(0);
}
