#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;

int N;
int main(){
    mat A(3, vec(3));
    A[0][0]=2;
    A[0][1]=1;
    A[0][2]=0;
    A[1][0]=2;
    A[1][1]=2;
    A[1][2]=2;
    A[2][0]=0;
    A[2][1]=1;
    A[2][2]=2;
    A=pow(A, N);
    cout << A[0][0] << endl;
}