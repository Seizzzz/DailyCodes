#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fun(char *str, int start, int end)
{
    char chLeft;
    char chRight;
    while((start<=end) && (str[start] != '\0'))
    {
        switch(str[start])
        {
            case '(':
                chLeft = str[start];
                chRight = ')';
                break;
            case ')':
                return 0;
            default:
                chLeft = '\0';
                break;
        }
        if(str[start] == chLeft)
        {
            int a = 1;
            int b=0;
            int t = start+1;
            while((t<=end) && (str[t] != '\0'))
            {
                if(str[t] == chLeft)
                    ++a;
                if(str[t] == chRight)
                    ++b;
                if(b>a)
                    return 0;
                if(a == b)
                {
                    if(0 == fun(str, start+1, t-1))
                        return 0;
                    start=t;
                    break;
                }
                ++t;
            }
            if(a>b)
                return 0;
        }
        ++start;
    }
    return 1;
}

int main()
{
    char str[120];
    gets(str);
    int length = strlen(str);
    int i = fun(str, 0, length-1);
    if(i == 1){
        printf("parentheses match!\n");
    }else{
        printf("parentheses do not match!\n");
    }
    return 0;
}
