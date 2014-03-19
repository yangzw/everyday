#include"calculator.h"
#define MAXVAL  100

int sp = 0;
double val[MAXVAL];

void push(double a)
{
    if(sp < MAXVAL)
        val[sp++] = a;
    else
        printf("error:the stack is full,can't push %f\n",a);
}

double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error:stack empty\n");
        return 0.0;
    }
}

double get_top(void)
{
    double top = pop();
    push(top);
    return top;
}

void copy_top(void)
{
    double top = pop();
    push(top);
    push(top);
}

void swap_toptwo(void)
{
    double top1 = pop();
    double top2 = pop();
    push(top2);
    push(top1);
}

void clear(void)
{
    sp = 0;
}
