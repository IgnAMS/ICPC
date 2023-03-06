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

ll dinero(string s) {
    int n = s.length();
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        if(s[i] == '.') continue;
        else ans = (ans * 10 + (s[i] - '0'));
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string init; cin>>init;
    ll curr = dinero(init);
    ll ans = 0;
    rep(i, n) {
        string s; cin>>s;
        curr += dinero(s);
        // cout<<dinero(s)<<' '<<curr<<'\n';
        if(curr % 100) ans++;
    }
    cout<<ans<<'\n';

    return 0;
}