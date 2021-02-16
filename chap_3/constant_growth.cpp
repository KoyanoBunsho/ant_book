#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define ll long long

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    ll res = 0;
    int right=1;
    rep(left, n) {
        while (right < n && (right <= left || a[right - 1] < a[right])) {
            ++right;
        }
        res += right - left;
        if (left == right) ++right;
    }
    cout << res << endl;
    return 0;
}