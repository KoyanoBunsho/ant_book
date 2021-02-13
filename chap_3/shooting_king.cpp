#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define ll long long

bool C(ll d, vector<ll> h, vector<ll> s, ll n){
    vector<ll> t(n, 0);
    bool ok=true;
    rep(i, n){
        if(d<h[i])ok=false;
        else t[i]=(d-h[i])/s[i];
    }
    sort(t.begin(), t.end());
    rep(i, n){
        if(t[i]<i)ok=false;
    }
    return ok;
}

int main(){
    int n;
    cin >> n;
    vector<ll> h(n);
    vector<ll> s(n);
    rep(i, n) cin >> h[i] >> s[i];
    ll left = 0;
    ll right = 1e18;
    while(right-left>1){
        ll mid = (right+left)/2;
        if (C(mid, h, s, n)) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}