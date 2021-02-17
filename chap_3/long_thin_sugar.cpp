#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(int i=0; i<n; i++)

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i];
    int res = 0;
    int right = 0;
    set<int> member;
    rep(left, n){
        while(right<n && !member.count(a[right])){
            member.insert(a[right]);
            ++right;
        }
        res = max(res, right-left);
        if(left==right)++right;
        else{
            member.erase(a[left]);
        }
    }
    cout << res << endl;
    return 0;
}