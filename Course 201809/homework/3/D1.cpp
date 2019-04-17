#include <stdio.h>
#include <math.h>

int main(void)
{
    float a, b, c;
    scanf("%f %f %f",&a,&b,&c);
    if(a == 0)
    {
        printf("The equation is not quadratic.\n");
    }
    float derta = b*b - 4*a*c;
    if(fabs(derta) <= 1e-6)
        printf("The equation has two equal roots: %.4f.\n",(-b)/(2*a));
    else if(derta > 0)
    {
        float x1 = (-b + sqrt(derta))/(2*a);
        float x2 = (-b - sqrt(derta))/(2*a);
        printf("The equation has two distinct real roots: %.4f and %.4f.\n",x1>x2?x1:x2,x2<x1?x2:x1);
    }
    else
    {
        float m = (-b)/(2*a);
        float n = sqrt(fabs(derta))/(2*a);
        printf("The equation has two complex roots: %.4f+%.4fi and %.4f-%.4fi.\n",m,n,m,n);
    }
    return 0;
}

