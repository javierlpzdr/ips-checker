//
//  helpers.h
//  Producto2
//
//  Created by Javier López (UOC) on 10/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//

#ifndef helpers_h
#define helpers_h

#include <stdio.h>
#include <stdbool.h>

void append(char* s, char c);
bool search(char string[], char match[]);
char * extract_between(const char *str, const char *p1, const char *p2);

#endif /* mstrings_h */
