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
    //generating forward difference table 
    for(int j=1;j<n;++j){
        for(int i=0;i<n-j;++i){
            y[i][j] = y[i+1][j-1]-y[i][j-1]; 
        }
    }
    printf("\n The froward difference table: \n");
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j < n - i; j++) 
            printf("%f\t", y[i][j]);
    }

    float sum = y[0][0];
    printf("\nInterpolation point:");
    float a,p=1.0;
    scanf("%f",&a);
    float h = x[1]-x[0];
    float u = (a-x[0])/h;
    printf("%f %f\n",h,u);
    for(int i=1;i<n;++i){
        p = p*(u-i+1)/i;
        sum+=p*y[0][i];
    }
    printf("%f",sum);
}