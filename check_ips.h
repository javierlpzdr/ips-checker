#pragma once

#ifndef check_ips_h

#define check_ips_h

#include <stdio.h>
#include <stdbool.h>
#include "helpers.h"
#include "terminal.h"

void exec_ip_ping(char file[200], char ip[20], char content[10000]);
void get_ips_from_file(FILE* fp, char ips[4][20]);
void get_correct_ips(char test_file[200]);
int checkIps();

#endif /* check_ips_h */

