#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
const int MAX_N = 100005;

int N, P, L;
int A[MAX_N + 1], B[MAX_N + 1];

int main() {
  cin >> N >> P >> L;
  rep(i, N) { cin >> A[i]; }
  rep(i, N) { cin >> B[i]; }
  A[N] = L;
  B[N] = 0;
  N++;
  priority_queue<int> q;
  int ans = 0, pos = 0, tank = P;
  rep(i, N) {
    int d = A[i] - pos;
    while (tank - d < 0) {
      if (q.empty()) {
        cout << "-1" << endl;
        return 0;
      }
      tank += q.top();
      q.pop();
      ans++;
    }
    tank -= d;
    pos = A[i];
    q.push(B[i]);
  }
  cout << ans << endl;
  return 0;
}
