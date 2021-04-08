#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)

const int MAX_N = 100005;

int  bit[MAX_N+1], n, a[MAX_N];

int sum(int i){
    int s = 0;
    while(i > 0){
        s += bit[i];
        i -= i&(-i);
    }
    return s;
}

void add(int i, int x){
    while(i <= n){
        bit[i] += x;
        i += i&(-i);
    }
}

int main(){
    ll ans = 0;
    cin >> n;
    rep(i, n)cin >> a[i];
    rep(j, n){
        ans += j - sum(a[j]);
        add(a[j], 1);
    }
    cout << ans << endl;
    return 0;
}