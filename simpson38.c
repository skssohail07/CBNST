#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x) 1/(1+x*x)
int main(){
    printf("Enter upper, lower, sub:");
    float upper,lower,sub;
    scanf("%f %f %f",&upper,&lower,&sub);
    float stepsize = (upper-lower)/sub;
    float x = upper-lower;
    float integration = 0,integration1=0;
    for(int i=1;i<sub;++i){
        lower+=stepsize;
        if(i%3==0)
        integration1+=f(lower);
        else
        integration+=f(lower);
    }
    integration = (2*integration1+x+3*integration)*stepsize*3/8; 
    printf("%f",integration);
}