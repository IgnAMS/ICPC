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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string t; cin>>t;
    map<string, int> mp = {{"Mon", 0}, {"Tue", 1}, {"Wed", 2}, {"Thu", 3}, {"Fri", 4}, {"Sat", 5}, {"Sun", 6}};
    ll x = mp[t];
    ll n; cin>>n;
    vl D(n); rep(i, n) cin>>D[i];
    ll Cicle[] = {30, 30, 30, 32, 31};
    ll next[] = {2, 3, 4, 0, 0};
    ll cicle = 30 * 2 + 31;
    ll mn = 7e9;
    rep(i, n) {
        // cerr<<(x - D[i] + 7000000000LL) % 7<<'\n';
        ll j = (x - D[i] + 7000000000LL) % 7;
        ll aux = 0;
        while((j == 1 or j == 3) and aux < (D[i] + (D[i] == 0))) aux += Cicle[j], j = next[j];
        ll k = max(0LL, (D[i] - aux) / cicle - 1);
        // ll k = (D[i] - aux) / cicle - 1;
        
        // cout<<aux<<' '<<D[i] - aux<<' '<<cicle<<'\n';
        while(aux + k * cicle < (D[i] + (D[i] == 0))) {
            aux += Cicle[j];
            j = next[j];
        }
        // cout<<aux + k * cicle<<'\n';
        mn = min(mn, aux + k * cicle - D[i]);
        // cout<<aux + k * cicle - D[i]<<'\n';
    }
    cout<<mn<<'\n';


    return 0;
}