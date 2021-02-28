# include <stdio.h>
# include "myMath.h"

int main (){
    double x; 
    printf("Please insert a real number:");
    scanf("%lf", &x);
    double tmp=x;
    if(tmp>=0)
    {
    tmp=(int)x;
    }    
    else
    {
     tmp=-tmp;
     tmp=(int)tmp;
     tmp=-tmp;
     if(tmp!=x)
     {
     tmp--;
     }
    }
    printf("1) The value of f(x)=e^x+x^3-2 at the point %lf is:  %.4f \n" ,x ,sub(add(Exponent(tmp), Power(x,3)),2));
    printf("2) The value of f(x)=3x+2x^2 at the point %lf is: %.4f \n",x , add(mul(x,3), mul(Power(x,2),2)));
    printf("3) The value of f(x)=(4x^3)/5-2x at the point %lf is: %.4f \n",x ,sub(div(mul(Power(x,3),4),5),mul(x,2)));
    return 0;
}
