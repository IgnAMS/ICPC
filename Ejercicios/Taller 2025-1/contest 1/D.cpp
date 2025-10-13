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
    ll d, n1, n2; cin>>d>>n1>>n2;
    ll C[n1]; rep(i, n1) cin>>C[i];
    ll D[n2]; rep(i, n2) cin>>D[i];


    int i1 = 0, i2 = 0;
    while(i1 < n1) {
        if(d >= C[i1]) d -= C[i1], i1++;
        else if(i2 < n2) d += D[i2], i2++;
        else if(i2 == n2) break; 
    }
    if(i1 == n1) i2 = n2;
    cout<<i1 + i2<<'\n';

    return 0;
}