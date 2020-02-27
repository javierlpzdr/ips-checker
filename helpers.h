#ifndef helpers_h
#define helpers_h

#include <stdio.h>
#include <stdbool.h>

void append(char* s, char c);
bool search(char string[], char match[]);
void copy(char* str1, char* str2);
void concat(char* str1, char* str2);
bool is_bigger(float a, float b);
char* extract_between(const char* str, const char* p1, const char* p2);

#endif /* mstrings_h */