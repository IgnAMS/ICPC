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
    int t; cin>>t;
    while(t--) {
        int n, a, q; cin>>n>>a>>q;
        string s; cin>>s;
        bool yes = 0;
        bool maybe = 0;
        if(n == a) yes = 1;
        ll curr = a;
        rep(i, q) {
            if(s[i] == '+') a++, curr++;
            else a--;
            if(n == a) yes = 1;
        }
        if(yes) cout<<"YES\n";
        else if(curr >= n) cout<<"MAYBE\n";
        else cout<<"NO\n";

    }
    return 0;
}