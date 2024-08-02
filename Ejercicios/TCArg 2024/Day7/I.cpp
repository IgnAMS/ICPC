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


vector<string> X[5] = {
{
    "***", 
    "*.*", 
    "***", 
    "*.*", 
    "*.*"
},
{
    "***",
    "*.*",
    "***",
    "*.*",
    "***"
}, 
{
    "***", 
    "*..", 
    "*..", 
    "*..", 
    "***" 
},
{
    "***", 
    "*.*", 
    "*.*", 
    "*.*", 
    "***" 
},
{
    "***",
    "*..",
    "***",
    "*..",
    "***"
}
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string s; cin>>s;

    char mat[5][3 * n];
    rep(i, n) {
        rep(j, 5) repx(k, 3 * i, 3 * (i + 1)) {
            // cerr<<j<<' '<<k<<' '<<s[i] - 'A'<<'\n';
            // cerr<<X[s[i] - 'A'].size()<<'\n';
            mat[j][k] = X[s[i] - 'A'][j][k % 3]; 
        }
    }
    rep(i, 5) {
        rep(j, 3 * n) cout<<mat[i][j];
        cout<<'\n';
    }



    return 0;
}