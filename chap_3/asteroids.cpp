#include<bits/stdc++.h>
using namespace std;

int N, K;
const int MAX_K=100005;
int R[MAX_K], C[MAX_K];

int main(){
    V=N*2;
    for(int i=0; i<K; i++){
        add_edge(R[i]-1, N+C[i]-1);
    }
    cout << bipartite_matching << endl;
}