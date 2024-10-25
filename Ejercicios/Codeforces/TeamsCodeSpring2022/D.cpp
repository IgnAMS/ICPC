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

ll cont[2][26];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    string a, b; cin>>a>>b;
    rep(i, n) {
        cont[0][a[i] - 'a']++;
        cont[1][b[i] - 'a']++;
    }
    ll ans = 0;
    rep(i, 26) ans += abs(cont[0][i] - cont[1][i]);
    cout<<ans / 2<<'\n';



    return 0;
}