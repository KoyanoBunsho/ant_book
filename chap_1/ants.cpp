#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 1000000;
int L, n;
int x[MAX_N];

void solve(){
    cin >> L >> n;
    for(int i=0; i<n; i++) cin >> x[i];
    int minT = 0;
    for(int i=0; i<n; i++){
        minT = max(minT, min(x[i], L-x[i]));
    }
    int maxT = 0;
    for(int i=0; i<n; i++){
        maxT = max(maxT, max(x[i], L-x[i]));
    }
    cout << minT << ' ' << maxT << endl;
}

int main(){
    solve();
    return 0;
}