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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    ll F[2][2];
    memset(F, 0, sizeof(F));
    ll imp = 0, par = 0;
    rep(i, n) {
        int c = s[i] - 'a';
        F[c][i & 1]++;
        imp += F[c][i & 1], par += F[c][!(i & 1)];
    }
    cout<<par<<' '<<imp<<'\n';


    return 0;
}