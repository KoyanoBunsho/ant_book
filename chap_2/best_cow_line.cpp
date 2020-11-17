#include<bits/stdc++.h>
using namespace std;

const int MAX_N = 100005;
int N;
char S[MAX_N+1];

int main(){
    cin >> N;
    cin >> S;
    int a = 0, b = N-1;
    while(a<=b){
        bool left = false;
        for(int i=0; 1+i<=b; i++){
            if(S[a+i]<S[b-i]){
                left = true;
                break;
            }
            else if(S[a+i]>S[b-i]){
                left = false;
                break;
            }
        }
        if(left)putchar(S[a++]);
        else putchar(S[b--]);
    }
    putchar('\n');
    return 0;
}