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
    int x, y, z; cin>>x>>y>>z;
    int x1, y1, z1; cin>>x1>>y1>>z1;
    
    vl A(6); rep(i, 6) cin>>A[i];

    ll ans = 0;
    if(y < 0) ans += A[0];
    if(y > y1) ans += A[1];
    if(z < 0) ans += A[2];
    if(z > z1) ans += A[3];
    if(x < 0) ans += A[4];
    if(x > x1) ans += A[5];
    cout<<ans<<'\n';


    return 0;
}