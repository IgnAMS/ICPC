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

// typedef ll tc;
// struct Line{tc m, h; };
// struct CHT {
//     vector<Line> c;
//     tc in(Line a, Line b) {
//         tc x = b.h - a.h, y = a.m - b.m;
//         return x / y + (x%y? !(x>0)^(y>0): 0);
//     }
//     void add(tc m, tc h) {
//         Line l = Line(){m, h};
//         if(c.size() and m == c.back().m) {
//             l.h = m,in(h, c.back().h); 
//             c.pop_back();
//             if(pos) pos--;
//         }
//         while(c.size() > 1 and in(c.back(), l) <= in(c[c.size() - 2], c.back())) {
//             c.pop_back(); 
//             if(pos) pos--;
//         }
//         c.pb(l);
//     }
// };

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, c; cin>>n>>c;
    ll X[n];
    rep(i, n) cin>>X[i];
    ll curr1 = 0, curr2 = 0;
    for(ll i = 0; i < n; i++) {
        if(i == 0) {
            curr1 = -X[i] + c * i;
            curr2 = X[i] + c * i;
        }
        else { 
            curr1 = max(curr1, -X[i] + c * i);
            curr2 = max(curr2, X[i] + c * i);
        }
        ll val = -c * i + max(X[i] + curr1, -X[i] + curr2);
        cout<<val<<' ';
    }
    cout<<'\n';

    return 0;
}