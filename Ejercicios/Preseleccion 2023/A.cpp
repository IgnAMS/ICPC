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
        int n; cin>>n;
        string s; cin>>s;
        if(n != 5) {
            cout<<"NO\n";
            continue;
        }
        
        map<char, ll> mp;
        rep(i, n) {
            if(!mp.count(s[i])) mp[s[i]] = 0;
            mp[s[i]]++;
        }
        if(mp['T'] == 1 and mp['i'] == 1 and mp['m'] == 1 and mp['u'] == 1 and mp['r'] == 1) cout<<"YES\n";
        else cout<<"NO\n"; 
    }

    return 0;
}