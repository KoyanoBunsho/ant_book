#include<bits/stdc++.h>
using namespace std;

const int MAX_V = 100005;
int d[MAX_V][MAX_V];
int V;

void warshall_floyd(){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            for(int k=0; k<V; k++){
                d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
            }
        }
    }
}