#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x) x*x*x
int main(){
    printf("Enter upper, lower, sub:");
    float upper,lower,sub;
    scanf("%f %f %f",&upper,&lower,&sub);
    float stepsize = (upper-lower)/sub;
    float x = upper-lower;
    float integration = 0;
    for(int i=1;i<sub;++i){
        lower+=stepsize;
        integration += f(lower); 
    }
    
    integration = (2*integration+x)*stepsize/2; 
    printf("%f",integration);
}