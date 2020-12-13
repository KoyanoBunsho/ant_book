#include<bits/stdc++.h>
using namespace std;

const int MAX_P = 100005;
int P;
int a[MAX_P];

int main(){
    cin >> P;
    for(int i=0; i<P; i++)cin >> a[i];
    set<int> all;
    for(int i=0; i<P; i++)all.insert(a[i]);
    int n=all.size();
    int s=0, t=0, num=0;
    map<int, int> count;
    int res=P;
    for(;;){
        while(t<P && num<n){
            if(count[a[t++]]++ == 0)num++;
        }
        if(num<n)break;
        res=min(res, t-s);
        if(--count[a[s++]]==0)num--;
    }
    cout << res << endl;
}