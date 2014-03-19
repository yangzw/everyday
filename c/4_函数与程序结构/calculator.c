#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"calculator.h"

#define MAXOP   100

void math_function(char s[]);

int main()
{
    int i,type,var = 0;
    double op2,v;
    double variable[26]; //26个变量
    for(i=0;i<26;i++)
        variable[i] = 0.0;
    char s[MAXOP];
    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
                push(atof(s));
                break;
            case MATH:  //数学函数
                putchar('m');
                math_function(s);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error:zero divisor\n");
                break;
            case '%':   //浮点数求余
                op2 = pop();
                if(op2 != 0.0)
                    push(fmod(pop(),op2));
                else
                    printf("error:zero divisor\n");
                break;
            case '?':
                printf("Top of stack:%f\n",get_top());
                break;
            case 'd':
                clear();
                printf("clear the stack\n");
                break;
            case 'c':
                copy_top();
                printf("copy the top in stack\n");
                break;
            case 's':
                swap_toptwo();
                printf("swap the top two of stack\n");
                break;
            case '\n':
                v = pop();
                printf("\t%.8g\n",v);
                break;
            case '=':   //变量赋值
                pop();
                if(var >= 'A' && var <= 'Z')
                {
                    variable[var - 'A'] = pop();
                    push(variable[var - 'A']);
                }
                else
                    printf("error:no variable name\n");
                break;
            default:
                if(type >= 'A' && type <= 'Z')
                    push(variable[type - 'A']);
                else if(type == 'v')    //v代表栈顶的值
                    push(v);
                else
                    printf("error:unknown command %s\n",s);
                break;
        }
        var = type;
    }
    return 0;
}

void math_function(char s[])
{
    double op2;
    if(strcmp(s,"sin") == 0)
        push(sin(pop()));
    else if(strcmp(s,"cos") == 0)
        push(cos(pop()));
    else if(strcmp(s,"exp") == 0)
        push(exp(pop()));
    else if(strcmp(s,"pow") == 0)
    {
        op2 = pop();
        push(pow(pop(),op2));
     }
    else
        printf("error: %s not supported\n",s);
}
