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


// 1 -> empty
// 2 -> empty
// 3 -> [1, 2], [3]
// 4 -> [1, 4], [2, 3]
// 5 -> empty
// 6 -> empty
// 7 -> [1, 2, 4, 7], [3, 5, 6]
// 8 -> [1, 2, 3, 4, 8], [5, 6, 7]
// 11 -> [1, 2, 3, 4, 5, 7, 11], [6, 8, 9, 10]
// 12 -> [1, 2, 3, 4, 5, 6, 7, 11], [8, 9, 10, 12]
// 15 -> [1 2 3 4 5 6 7 8 9 15], [10 11 12 13 14]
// 16 ->  [1 2 3 4 5 6 7 8 9 10 13], [11 12 14 15 16]

ll V[1000002];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll suma = n * (n + 1) / 2;
    if(suma % 2) {
        cout<<"NO\n";
        return 0;
    }
    vl A, B; 
    ll curr = 0;
    for(ll x = n; x >= 1 and suma / 2 - curr > 0; x--) {
        ll res = suma / 2 - curr;
        if(res < x) {
            A.pb(res);
            V[res] = 1;
            break;
        }
        curr += x;
        A.pb(x);
        V[x] = 1;
    }
    repx(i, 1, n + 1) if(!V[i]) B.pb(i);
    cout<<"YES\n";
    cout<<A.size()<<'\n';
    for(auto u: A) cout<<u<<' '; cout<<'\n';
    cout<<B.size()<<'\n';
    for(auto u: B) cout<<u<<' '; cout<<'\n';

    return 0;
}