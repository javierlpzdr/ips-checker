//
//  show_network_adapter.h
//  Producto2
//
//  Created by Javier López (UOC) on 11/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#ifndef show_network_adapter_h
#define show_network_adapter_h

#include <stdio.h>
#include "../utils/helpers.h"
#include "../utils/terminal.h"

void save_adapter(char * path, char * adapter);
char * get_adapter(char * path);
int show_network_adapter();
int checkIps();

#endif /* show_network_adapter_h */
