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
    ll X[3]; cin>>X[0]>>X[1]>>X[2];
    sort(X, X + 3);

    if(X[0] == X[2]) cout<<X[0]<<'\n';
    else {
        X[2] -= X[0], X[1] -= X[0];

        // max h1 + h2
        // 2 * h1 + h2 <= x1
        // 2 * h2 + h1 <= x2

        ll l = 0, r = min(X[1], X[2] / 2);
        while(l < r) {
            int m = (l + r) / 2;
            if(X[2] - 2 * m < X[1] - m) r = m;
            else l = m + 1;
        }
        cout<<l<<'\n';
        
        // l es el punto mas pequeño tal que X[2] es menor a X[1]
        ll x = 0;
        if(l == 0) {
            // si l = 0 -> no se puede formar nada xd
            x = 0;
        }
        else {
            ll rest = min({(X[2] - 2 * l) / 3, (X[1] - l) / 3});
            bool xd = 0;
            if(X[2] - 2 * l - rest * 3 >= 1 and X[1] - l - rest * 3 >= 2) xd = 1;
            x = l + rest + xd;

            l--;
            cout<<X[2] - 2 * l<<' '<<X[1] - l<<'\n';
            rest = min({(X[2] - 2 * l) / 3, (X[1] - l) / 3});
            xd = 0;
            if(X[2] - 2 * l - rest * 3 >= 2 and X[1] - l - rest * 3 >= 1) xd = 1;
            x = max(x, l + rest + xd);
        }
 
        
        cout<<X[0] + x<<'\n';
    }




    return 0;
}