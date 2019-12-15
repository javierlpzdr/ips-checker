//
//  check_ips.h
//  Producto2
//
//  Created by Javier López (UOC) on 11/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#ifndef check_ips_h
#define check_ips_h

#include <stdio.h>
#include <stdbool.h>
#include "../utils/helpers.h"
#include "../utils/terminal.h"

void get_ips_from_file(FILE *fp, char (ips)[4][20]);
char * exec_ip_ping(char file[200], char ip[20]);
void get_correct_ips(char test_file[200]);
int checkIps();

#endif /* check_ips_h */
