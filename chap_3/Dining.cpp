#include<bits/stdc++.h>
using namespace std;

int N, F, D;
const int MAX_N=10005;
const int MAX_F=10005;
const int MAX_D=10005;

bool likeF[MAX_N][MAX_F];

int main(){
    int a=N*2+F+D, t=s+1;
    for(int i=0; i<F; i++){
        add_edge(s, N*2+i, 1);
    }
    for(int i=0; i<N; i++){
        add_edge(i, N+i, 1);
        for(int j=0; j<F; j++){
            if(likeF[i][j])add_edge(N*2+j, i, 1);
        }
        for(int j=0; j<D; j++){
            if(likeD[i][j])add_edge(N+i, N*2+F+j, 1);
        }
    }
    cout << max_flow(s, t);
}