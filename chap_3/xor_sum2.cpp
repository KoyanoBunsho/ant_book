#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll left = 0;
    a.push_back((1LL<<21)-1);
    ll res = 0;
    ll right = 0;
    ll bit = 0;
    for(left=0; left<n;){
        if((bit & a[right])==0){
            bit |= a[right];
            if(right<n)++right;
        }else{
            ll bet = right - left;
            res += bet;
            bit &= ~a[left];
            ++left;
        }
    }
    cout << res << endl;
    return 0;
}