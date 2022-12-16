#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	float A[n][n+1];
	float sol[n];
	for(int i=0;i<n;++i){
		for(int j=0;j<n+1;++j){
			scanf("%f",&A[i][j]);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
            if(A[i][i]==0){
                printf("Mathematical Error");
                exit(0);
            }   
			if(i!=j){
				float c = A[j][i]/A[i][i];
				for(int k=0;k<n+1;++k){
					A[j][k] = A[j][k] - c*A[i][k];
					//printf("A[%d][%d] = %f",j,k,A[j][k]);
				}
			}
		}
	}
    for(int i=0;i<n;++i){
        sol[i]= A[i][n+1-1]/A[i][i];
    }
	for(int i=0;i<n;++i)
		printf("\nx%d=%f\t",i,sol[i]);
	return 0;
}