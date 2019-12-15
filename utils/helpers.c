//
//  helpers.c
//  Producto2
//
//  Created by Javier López (UOC) on 10/12/2019.
//  Copyright © 2019 Javier López (UOC). All rights reserved.
//
#include <string.h>

#include "helpers.h"


void append(char* s, char c)
{
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}


bool search(char string[], char match[]) {
    if (strstr(string, match)) {
        return true;
    }
    
    return false;
}

char * extract_between(const char *str, const char *p1, const char *p2)
{
	char *ret;

  const char *i1 = strstr(str, p1);
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
       return ret;
     }
    }
  }
    
    return "0";
}

int leecad(char *cad, int n) {
    int i, c;
    c = getchar();
    
    if (c == EOF) {
        cad[0] = '\0';
        return 0;
    }
    
    if (c == '\n')
        i = 0;
    else {
        cad[0] = c;
        i = 1;
    }
    
    for (; i < n - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        cad[i] = c;
        cad[i] = '\0';
    
    if (c != '\n' && c != EOF)
        while ((c = getchar()) != '\n' && c != EOF);
    
    return 1;
};

bool is_bigger(a, b) {
    return a > b;
}
