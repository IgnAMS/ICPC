#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
#include<set>
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
vector<pll> vec = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    pll X[n];
    map<ll, ll> x, y;
    rep(i, n) {
        cin>>X[i].ff>>X[i].ss;
        x[X[i].ff]++;
        y[X[i].ss]++;
    }

    if(n == 1) {
        cout<<"1\n";
        return 0;
    }

    ll lado1 = x.rbegin()->ff - x.begin()->ff + 1, lado2 = y.rbegin()->ff - y.begin()->ff + 1;
    if(lado1 < lado2) swap(lado1, lado2);
    // lado1 es siempre el mas grande
    ll dif = min(k, lado1 - lado2);
    lado2 += dif;
    lado1 += (k-dif)/2;
    lado2 += (k+1-dif)/2;
    ll ans = lado1 * lado2;

    // cout<<1e5 * 20 * (2*2 + 2 + 4*2 + 4*2*2)<<"\n";
    rep(i, n) {
        if(--x[X[i].ff] == 0) x.erase(X[i].ff);
        if(--y[X[i].ss] == 0) y.erase(X[i].ss);
        rep(j, 4) {
            x[X[i].ff + vec[j].ff * k]++;
            y[X[i].ss + vec[j].ss * k]++;
            ans = max(
                ans,
                (x.rbegin()->ff - x.begin()->ff + 1) * (y.rbegin()->ff - y.begin()->ff + 1)
            );
            if(--x[X[i].ff + vec[j].ff * k] == 0) x.erase(X[i].ff + vec[j].ff * k);
            if(--y[X[i].ss + vec[j].ss * k] == 0) y.erase(X[i].ss + vec[j].ss * k);
        }
        x[X[i].ff]++;
        y[X[i].ss]++;
    }

    cout<<ans<<"\n";
    
    return 0;
}