#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define ll long long

bool C(ll d, ll r, ll b, ll x, ll y){
    ll num1 = (r-d)/(x-1);
    ll num2 = (b-d)/(y-1);
    return num1+num2>=d;
}

int main(){
    ll r, b, x, y;
    cin >> r >> b >> x >> y;
    ll left = 0;
    ll right = min(r, b)+1;
    while(right-left>1){
        ll mid = (right+left)/2;
        if(C(mid, r, b, x, y))left=mid;
        else right=mid;
    }
    cout << left << endl;
    return 0;
}