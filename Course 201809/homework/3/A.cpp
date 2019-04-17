#include <stdio.h>
#include <ctype.h>
int main() 
{
    char str[100], *c;
    gets(str);
    for (c = str; *c; c++) 
	{
        if (islower(*c)) 
		{
            if (*c >= 'x') 
			{
				*c -= 23;
			}
            else *c += 3;
        } 
		else if (islower(*c)) 
		{
            if (*c <= 'C')
			{
            	*c += 23;
			}
            else *c -= 3;
        }
    }
    puts(str);
    return 0;
}
