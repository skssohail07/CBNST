#include <stdio.h>

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
			if(j>i){
				float c = A[j][i]/A[i][i];
				for(int k=0;k<n+1;++k){
					A[j][k] = A[j][k] - c*A[i][k];
				}
			}
		}
	}
	sol[n-1]= A[n-1][n+1-1]/A[n-1][n-1];
	for(int i=n-2;i>=0;i--){
	float sum =0;
	for(int j =i+1;j<n;++j){
		sum+=A[i][j]*sol[j];
		printf("%f\n",sum);
	}
	sol[i] = (A[i][n-1+1]-sum)/A[i][i];
	}
	for(int i=0;i<n;++i)
		printf("\nx%d=%f\t",i,sol[i]);
	return 0;
}