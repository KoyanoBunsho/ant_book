#include<bits/stdc++.h>
using namespace std;

int N, M;
int A[MAX_N], B[MAX_N];
int a[MAX_M], b[MAX_M], w[MAX_M];

int main(){
    int s=N, t=s+1;
    for(int i=0; i<N; i++){
        add_edge(i, t, A[i]);
        add_edge(s, i, B[i]);
    }
    for(int i=0; i<M; i++){
        add_edge(a[i]-1, b[i]-1, w[i]);
        add_edge(b[i]-1, a[i]-1, w[i]);
    }
    cout << max_flow(s, t) << endl;
}