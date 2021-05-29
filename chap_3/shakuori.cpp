#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long
int main() {
  int n, Q;
  cin >> n >> Q;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  rep(j, Q) {
    ll x;
    cin >> x;
    ll res = 0;
    int right = 0;
    ll sum = 0;
    rep(left, n) {
      while (right < n && sum + a[right] <= x) {
        sum += a[right];
        ++right;
      }
      res += (right - left);
      if (right == left)
        ++right;
      else
        sum -= a[left];
    }
    cout << res << endl;
  }
  return 0;
}
