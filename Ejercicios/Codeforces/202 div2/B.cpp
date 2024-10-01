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
    ll v; cin>>v;
    ll n = 9;
    ll A[n];
    ll mn = 1e6;
    rep(i, n) {
        cin>>A[i];
        mn = min(mn, A[i]);
    }
    // xddddd
    ll digits = v / mn;
    string s = ""; 
    rep(d, digits) {
        for(int i = 8; i >= 0; i--) {
            if(v >= A[i] and (v - A[i]) / mn >= digits - d - 1) {
                s += char('0' + i + 1);
                v -= A[i];
                break;
            }
        }
    }
    if(s.length() == 0) cout<<"-1\n";
    else cout<<s<<'\n';



    return 0;
}