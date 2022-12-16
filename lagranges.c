#include<stdio.h>
#include<conio.h>
int main(){
    float x[20],y[20];
    int n;
    printf("Enter number of entries:");
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        printf("Enter the values for x[%d]:",i);
        scanf("%f",&x[i]);
        printf("Enter the values for y[%d]:",i);
        scanf("%f",&y[i]);
    }
    printf("Enter interpolation point:");
    float xp,yp=0;
    scanf("%f",&xp);
    for(int i=1;i<n;++i){
        float p=1.0;
        for(int j=1;j<n;++j){
            if(i!=j)
                p*=(xp-x[j])/(x[i]-x[j]);
        }
        yp+=p*y[i];
    }
    printf("Interpolated value:%f",yp);
    return 0;
}