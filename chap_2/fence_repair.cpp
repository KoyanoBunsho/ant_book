#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 100005;
int N, L[MAX_N];

int main(){
    ll ans = 0;
    cin >> N;
    for(int i=0; i<N; i++)cin >> L[i];
    while(N>1){
        int mii1 = 0, mii2 = 1;
        if(L[mii1] > L[mii2])swap(mii1, mii2);
        for(int i=2; i<N; i++){
            if(L[i]<L[mii1]){
                mii2 = mii1;
                mii1 = i;
            }
            else if(L[i]<L[mii2])mii2 = i;
        }
    int t = L[mii1]+L[mii2];
    ans += t;
    if(mii1==N-1)swap(mii1, mii2);
    L[mii1] = t;
    L[mii2] = L[N-1];
    N--;
    }
    cout << ans << endl;
    return 0;
}