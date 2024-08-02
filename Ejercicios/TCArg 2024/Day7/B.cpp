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
    ll b, d, s; cin>>b>>d>>s;
    ll d_falta = max(
        max(b, s) - 1 - d,
        0LL
    );
    ll b_falta = max(
        max(d, s) - 1 - b,
        0LL
    );
    ll s_falta = max(
        max(b, d) - 1 - s,
        0LL
    );
    // cout<<b_falta<<' '<<d_falta<<' '<<s_falta<<'\n';
    cout<<d_falta + b_falta + s_falta<<'\n';



    return 0;
}