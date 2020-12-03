#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAX_L = 1000000005;
const int MAX_SQRT_B = 1000000005;
bool is_prime[MAX_L];
bool is_prime_small[MAX_SQRT_B];

ll segment_sieve(ll a, ll b){
    ll p =0;
    for(int i=0; (ll)i*i<b; i++)is_prime_small[i]=true;
    for(int i=0; i<b-a; i++)is_prime[i]=true;
    for(int i=2; (ll)i*i<b; i++){
        if(is_prime_small[i]){
            p++;
            for(int j=2*i; (ll)j*j<b; j+=i)is_prime_small[j]=false;
            for(ll j=max(2LL, (a+i-1)/i)*i; j<b; j+=i)is_prime[j-1]=false;
        }
    }
    return p;
}

int main(){
    ll a, b, ans;
    cin >> a >> b;
    ans = segment_sieve(a, b);
    cout << ans << endl;
    return 0;
}