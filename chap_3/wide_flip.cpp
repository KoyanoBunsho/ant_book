#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define ll long long

bool ok(int k, int N, string s){
    set<int> st;
    int l=N-k, r=k;
    for(int i=l; i<r; i++){
        st.insert(s[i]);
    }
    return (int)st.size()<=1;
}

int main(){
    string s;
    cin >> s;
    int N = s.size();
    int lo=1, hi=N;
    if(ok(N, N, s)){
        lo=N;
    }
    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(ok(mid, N, s))lo=mid;
        else hi=mid;
    }
    cout << lo << endl;
    return 0;
}