#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x,y) x+y
int main(){
    printf("Enter x0, y0, xn, sub:");
    float sub,x0,y0,xn,yn;
    scanf("%f %f %f %f",&x0,&y0,&xn,&sub);
    float stepsize = (xn-x0)/sub;
    for(int i=0;i<sub;++i){
        float slope=f(x0,y0);
        yn=y0+stepsize*slope;
        printf("%.4f\t%.4f\t%0.4f\t%.4f\n",x0,y0,slope,yn);
        y0=yn;
        x0+=stepsize;
    }
    printf("yn:%f",yn);

}