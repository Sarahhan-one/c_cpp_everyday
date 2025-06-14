#ifndef __DAY05_H__
#define __DAY05_H__
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define size_ary(a) (sizeof(a)/sizeof((a)[0]))
void array_pointer_ex2(void);
char* my_strcpy(char* to, const char* from);
unsigned int my_strlen(const char* str);
char* my_strcat(char* s, const char* append);
void f01_8b(void);
void f09_2(void);
char* to_upper01(char* name, int size);
char* to_upper02(char* name, int size);
void f08_6(void);

#endif