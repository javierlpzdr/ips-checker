#ifndef show_network_adapter_h

#define show_network_adapter_h

#include <stdio.h>
#include "helpers.h"
#include "terminal.h"

void save_adapter(char* path, char* adapter);
void get_adapter(char* path);
int show_network_adapter();
int checkIps();

#endif /* show_network_adapter_h */

