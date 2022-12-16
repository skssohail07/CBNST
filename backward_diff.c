#include<stdio.h>
#include<conio.h>
int main(){
    float x[20],y[20][20];
    int n;
    printf("Enter number of entries:");
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        printf("Enter the values for x[%d]:",i);
        scanf("%f",&x[i]);
        printf("Enter the values for y[%d]:",i);
        scanf("%f",&y[i][0]);
    }
    //generating backward difference table 
    for(int j=1;j<n;++j){
        for(int i=j;i<n;++i){
            y[i][j] = y[i][j-1]-y[i-1][j-1]; //different than forward
        }
    }
    printf("\n The froward difference table: \n");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j <= i; j++) //different than forward
            printf("%f\t", y[i][j]);
    }

    float sum = y[n-1][0];//different than forward
    printf("\nInterpolation point:");
    float a,p=1.0;
    scanf("%f",&a);
    float h = x[1]-x[0];
    float u = (a-x[n-1])/h;//different than forward
    printf("%f %f\n",h,u);
    for(int i=1;i<n;++i){
        p = p*(u-i+1)/i;
        sum+=p*y[n-1][i];//different than forward
    }
    printf("%f",sum);
}