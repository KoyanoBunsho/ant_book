#include<bits/stdc++.h>
using namespace std;

int N, K;
bool can[MAX_N][MAX_K];

int main(){
    int s=N+K, t=s+1;
    for(int i=0; i<N; i++){
        add_edge(s, i, 1);
    }
    for(int i=0; i<K; i++){
        add_edge(N+i, t, 1);
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            if(can[i][j]){
                add_edge(i, N+j, i);
            }
        }
    }
    cout << max_flow(s, t);
}