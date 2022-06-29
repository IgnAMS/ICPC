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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

vector<vi> T(510, vi(2010, 0));
ll n;
void update(ll x, ll posr, ll posc, ll l = 0, ll r = n - 1, ll u = 0) {
    if(l == r) T[posr][u] = x;
    else {
        ll m = (l + r) / 2;
        if(posc <= m) update(x, posr, posc, l, m, 2 * u + 1); 
        else update(x, posr, posc, m + 1, r, 2 * u + 2);
        T[posr][u] = T[posr][2 * u + 1] + T[posr][2 * u + 2];
    }
}

ll query(ll posr, ll i, ll j, ll l = 0, ll r = n - 1, ll u = 0) {
    if(l > j or r < i) return 0;
    if(i <= l and r <= j) return T[posr][u];
    ll m = (l + r ) / 2;
    return query(posr, i, j, l, m, 2 * u + 1) + query(posr, i, j, m + 1, r, 2 * u + 2);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; 
    while(t--) {
        ll q; 
        cin>>n>>q;
        rep(i, n) {
            string line; cin>>line;
            rep(j, n) update(line[j] - 'A' + 1, i, j);
        }
        while(q--) {
            int com; cin>>com;
            if(com == 0) {
                ll x, y; string line; cin>>x>>y>>line;
                if(x == 0) rep(i, n) update(line[i] - 'A' + 1, y, i);
                else rep(i, n) update(line[i] - 'A' + 1, i, y);
            }
            else {
                ll x1, y1, x2, y2; cin>>x1>>y1>>x2>>y2;
                ll sum = 0;
                repx(i, x1, x2 + 1) {
                    // cout<<query(i, y1, y2)<<'\n';
                    sum += query(i, y1, y2);
                }
                cout<<sum<<'\n'; 
            }
        }
    }





    return 0;
}