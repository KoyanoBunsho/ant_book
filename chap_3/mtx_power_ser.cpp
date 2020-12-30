#include<bits/stdc++.h>
using namespace std;

int n, k;
mat A;

int main(){
    mat B(n*2, vec(n*2));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            B[i][j]=A[i][j];
        }
        B[n+1][i]=B[n+i][n+i]=1;
    }
    B=pow(B, k+1);
    for(int i=0; i<n; i++){
        for)int j=0; j<n; j++{
            int a=B[n+1][j]%M;
            if(i==j)a=(a+M-1)%M;
        }
    }
}