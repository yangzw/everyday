#include<stdio.h>

void expand(char s1[],char s2[]);
inline int is_digit_or_alpha(char a);

int main()
{
    char s1[10] = "a-c-k-a";
    char s2[60] = "";
    expand(s1,s2);
    printf("s1:%s\ns2:%s\n",s1,s2);
    char s3[22] = "a-a-0eo-0-8-a-A-C-a-b";
    expand(s3,s2);
    printf("s3:%s\ns2:%s\n",s3,s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i;
    int j = 0,gap = 0;
    char front = ' ',after = ' ';
    int front_type = 0,after_type = 0;
    for(i = 0;s1[i] != '\0';i++)
    {
        front_type = is_digit_or_alpha(front);
        if(front_type && s1[i] == '-')
        {
            after = s1[i+1];
            if(after != '\0')
            {
                after_type =is_digit_or_alpha(after);
                if(after_type == front_type && (after - front) > 0)
                {
                    for(gap = 1;gap <= after - front;gap++)
                    {
                        s2[j++] = front + gap;
                    }
                    i++;
                    front = after;
                }
                else
                {
                    s2[j++] = s1[i++];
                    s2[j++] = after;
                    front = after;
                }
            }
            else
            {
                s2[j++] = s1[i];
                s2[j++] = after;
                break;
            }
        }
        else
        {
            s2[j++] = s1[i];
            front = s1[i];
        }
    }
}

inline int is_digit_or_alpha(char a)
{
    if(a >= 'a' && a <= 'z')
        return 1;
    else if(a >= 'A' && a <= 'Z')
        return 2;
    else if(a >= '0' && a <= '9')
        return 3;
    else
        return 0;
}
