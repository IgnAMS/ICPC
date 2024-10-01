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
        string s; cin>>s;
        int n = s.length();
        string t1 = "";
        string t2 = "";
        rep(i, n) t1 += '('; 
        rep(i, n) t1 += ')'; 
        rep(i, 2 * n) {
            if(i & 1) t2 += ')';
            else t2 += '('; 
        }
        bool oc1 = 1, oc2 = 1;
        rep(i, n + 1) {
            bool sub1 = 1, sub2 = 1;
            rep(j, n) {
                if(t1[i + j] != s[j]) sub1 = 0;
                if(t2[i + j] != s[j]) sub2 = 0;
            }
            // cout<<i<<' '<<sub1<<' '<<sub2<<'\n';
            if(sub1) oc1 = 0;
            if(sub2) oc2 = 0;
        }
        if(!oc1 and !oc2) {
            cout<<"NO\n";
        }
        else {
            cout<<"YES\n";
            if(oc1) cout<<t1<<'\n';
            else cout<<t2<<'\n';
        }


    }

    return 0;
}