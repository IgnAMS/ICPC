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
    vector<vector<string>> A(101, vector<string>());
    A[1] = {"1"};
    A[3] = {"169", "196", "961"};
    for(int k = 5; k <= 100; k += 2) {
        for(auto u: A[k - 2]) A[k].pb(u + "00");
        string s1 = "1", s2 = "9";
        rep(i, (k - 3) / 2) s1 += "0", s2 += "0";
        s1 += "6", s2 += "6";
        rep(i, (k - 3) / 2) s1 += "0", s2 += "0";      
        s1 += "9", s2 += "1";
        A[k].pb(s1);
        A[k].pb(s2);
    }

    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        for(string& u: A[n]) {
            cout<<u<<' '; 
        }
        cout<<'\n';
    }

    return 0;
}