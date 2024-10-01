#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        map<char, int> mp;
        for(auto u: s) {
            if(!mp.count(u)) mp[u] = 0;
            mp[u]++;
        }
        int x = 0;
        rep(i, s.size()) {
            if(mp[s[i]] == 1) { x = i; break; }
            mp[s[i]]--;
        }
        repx(i, x, s.size()) cout<<s[i]; cout<<'\n';
    }


    return 0;
}