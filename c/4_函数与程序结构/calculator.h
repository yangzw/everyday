#include<stdio.h>
#define NUMBER '0'
#define MATH    'n'
int getop(char []);
void push(double);
double pop(void);
double get_top(void);
void copy_top(void);
void swap_toptwo(void);
void clear(void);
int getch(void);
void ungetch(int);
