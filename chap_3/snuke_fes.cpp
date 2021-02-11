#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define ll long long

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    rep(i, n)cin >> a[i];
    rep(i, n)cin >> b[i];
    rep(i, n)cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    ll ans = 0;
    rep(i, n){
        ll a_cnt = lower_bound(a.begin(), a.end(), b[i])-a.begin();
        ll c_cnt = upper_bound(c.begin(), c.end(), b[i])-c.begin();
        ans += a_cnt*(n-c_cnt);
    }
    cout << ans << endl;
    return 0;
}