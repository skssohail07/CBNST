#include<stdio.h>
#include<math.h>
/*
Let the equations in diagonally ordered arrangement then modified be:
10x+y+z=15  -> x = (15-y-z)/10
x+10y+z=24  -> y = (24-x-z)/10
x+y+10z=33  -> z = (33-x-y)/10
*/

#define f1(x,y,z) (15-y-z)/10
#define f2(x,y,z) (24-x-z)/10
#define f3(x,y,z) (33-y-x)/10

int main(){
    float x0,y0,z0=0;//initial guess
    float x1,y1,z1;//next guesses
    float ex,ey,ez;//errors
    float e = 0.0001; // error limit
    do{
        x1 = f1(x0,y0,z0);
        y1 = f2(x1,y0,z0);
        z1 = f3(x1,y1,z0);

        //displaying 
        printf("%f\t%f\t%f\n",x1,y1,z1);

        ex = fabs(x1-x0);
        ey = fabs(y1-y0);
        ez = fabs(z1-z0);

        x0=x1;
        y0=y1;
        z0=z1;
    }while(ex>e && ey>e && ez> e);
    printf("Final Approximation:\nx=%f\ny=%f\nz=%f\n",x1,y1,z1);
    return 0;
}