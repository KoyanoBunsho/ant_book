#include<bits/stdc++.h>
using namespace std;

int N, M;
int Z[MAX_N][MAX_M];

int main(){
    int s=N+M*M, t=s+1;
    V=t+1;
    for(int i=0; i<N; i++){
        add_edge(s, i, 1, 0);
    }
    for(int j=0; j<M; j++){
        for(int k=0; k<N; k++){
            add_edge(N+j*N+k, t, 1, 0);
            for(int i=0; i<N; i++){
                add_edge(i, N+j*N+k, 1, (k+1)*Z[i][j]);
            }
        }
    }
    cout << (double)min_cost_flow(s, t, N)/N << endl;
}