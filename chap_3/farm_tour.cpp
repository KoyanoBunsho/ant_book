#include<bits/stdc++.h>
using namespace std;

int N, M;
const int MAX_M = 100005;
int a[MAX_M], b[MAX_M], c[MAX_M];

int main(){
    int s=0, t=N-1;
    V=N;
    for(int i=0; i<M; i++){
        add_edge(a[i]-1, b[i]-1, 1, c[i]);
        add_edge(b[i]-1, a[i]-1, 1, c[i]);
    }
    cout << min_cost_flow(s, t, 2) << endl;
}