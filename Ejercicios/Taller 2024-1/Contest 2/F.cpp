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

struct E {
    ll a, b, d;
};


E X[200005];
int n;

bool posible(int x) {
    int cont = 0;
    rep(i, n) {
        if(cont < x and X[i].a >= x - cont - 1 and X[i].b >= cont) cont++;
    }
    return cont == x;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        rep(i, n) {
            cin>>X[i].a>>X[i].b;
            X[i].d = i;
        }

        int l = 1, r = n;
        while(l < r) {
            int m = (l + r + 1) / 2;
            if(posible(m)) l = m;
            else r = m - 1;
        }
        cout<<l<<'\n';
    }


    return 0;
}