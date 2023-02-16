#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll bp(ll a, ll b) {
    a %= 10;
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % 10;
        a = (a * a) % 10;
        b /= 2;
    }
    return res;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll a, b; cin>>a>>b;
        cout<<bp(a, b)<<'\n';
    }


    return 0;
}