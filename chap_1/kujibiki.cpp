#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 10000000;
int n, m;
int kk[MAX_N];

bool binary_search(int x){
    int l=0, r=n*n;
    while(r-l>=l){
        int i = (l+r) / 2;
        if(kk[i]==x)return true;
        else if(kk[i]<x)l=i+1;
        else r=i;
    }
    return false;
}

void solve(){
    cin >> n >> m;
    for(int i=0; i<3; i++)cin >> kk[i];
    for(int c=0; c<n;c++){
        for(int d=0; d<n; d++){
            kk[c*n+d] = kk[c]+kk[d];
        }
    }
    sort(kk, kk+n*n);
    bool f=false;
    for(int a=0; a<n; a++){
        for(int b=0; b<n; b++){
            if(binary_search(m-kk[a]-kk[b])){
                f=true;
            }
        }
    }
}

int main(){
    solve();
    return 0;
}