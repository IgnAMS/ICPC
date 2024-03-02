#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    vl P(k); rep(i, k) cin>>P[i];
    ll ans = 0;
    // Sea divisible por toods los primos es igual a 
    repx(i, 1, (1<<k)) {
        ll num = 1;
        ll oc = 0;
        ll mult = -1;
        rep(j, k) if(i & (1<<j)) {
            if(num > n / P[j]) {
                oc = 1; 
                break;
            }
            num = num * P[j];
            mult *= -1;
        }
        if(oc) continue;
        ans = ans + (n / num) * mult;   
    }
    cout<<ans<<'\n';

    return 0;
}