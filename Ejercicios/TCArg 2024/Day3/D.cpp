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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    ll cont = 0;
    multiset<ll> S;
    for(int i = 30; i >= 0; i--) {
        if(n & (1LL<<i)) {
            cont++;
            S.insert((1<<i));
        }
    }
    if(cont > k) {
        cout<<"NO\n";
        return 0;
    }
    while(cont < k) {
        auto x = *S.rbegin();
        if(x == 1) break;
        S.erase(S.find(x));
        S.insert(x / 2), S.insert(x / 2);
        cont++;
    }
    if(cont < k) {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    for(auto u: S) cout<<u<<' '; cout<<'\n';




    return 0;
}