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
    int n, m; cin>>n>>m;
    map<string, string> mp;
    rep(i, n) {
        string s1, s2; cin>>s1>>s2;
        mp[s2] = s1;
    }
    rep(i, m) {
        string s1, s2; cin>>s1>>s2;
        string s3 = s2.substr(0, s2.length() - 1);
        cout<<s1<<' '<<s2<<" #"<<mp[s3]<<'\n';
    }





    return 0;
}