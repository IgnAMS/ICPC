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
    int t; cin>>t;
    while(t--) {
        ll x, y, k; cin>>x>>y>>k;
        rep(i, k - (k & 1)) {
            if(i & 1) cout<<x - i/2 - 1<<' '<<y<<'\n';
            else cout<<x + i/2 + 1<<' '<<y<<'\n';
        }
        if(k & 1) cout<<x<<' '<<y<<'\n';
    }




    return 0;
}