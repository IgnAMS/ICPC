#pragma GCC optimize("Ofast")
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, k; cin>>n>>m>>k;
    ll l = 0, r = n * m;
    while(l < r) {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        repx(i, 1, n + 1) cnt += min(m, mid / i);
        if(cnt >= k) r = mid;
        else l = mid + 1;
    }
    
    cout<<l<<'\n';


    return 0;
}