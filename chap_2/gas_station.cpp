#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
int N, L, P;
int A[MAX_N], B[MAX_N];

int main(){
    cin >> N >> L >> P;
    for(int i=0; i<N; i++)cin >> A[i];
    for(int i=0; i<N; i++)cin >> B[i];
    A[N] = L;
    B[N] = 0;
    N++;
    priority_queue<int> que;
    int ans =0, pos=0, tank=P;
    for(int i=0; i<N; i++){
        int d = A[i]-pos;
        while(tank-d<0){
            if(que.empty()){
                puts("-1");
                return 0;
            }
            tank += que.top();
            que.pop();
            ans++;
        }
        tank -= d;
        pos = A[i];
        que.push(B[i]);
    }
    cout << ans << endl;
    return 0;
}