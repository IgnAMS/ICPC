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
    ll A[3]; rep(i, 3) cin>>A[i];
    ll B[3]; rep(i, 3) cin>>B[i];
    ll sobra = 0, b = 0;
    ll falta = 0;
    rep(i, 3) {
        if(A[i] > B[i]) sobra += (A[i] - B[i]) / 2;
        if(A[i] < B[i]) falta += B[i] - A[i];
        if(b >= 2) sobra++, b = 0;
    }
    // cout<<falta<<' '<<sobra<<' '<<b<<'\n';
    if(sobra >= falta) cout<<"Yes\n";
    else cout<<"No\n";


    return 0;
}