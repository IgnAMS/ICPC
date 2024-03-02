#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

ll MOD = 1e9+7;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    multiset<ll> Buy, Sell, Mid;
    Buy.insert(-1);
    Sell.insert(1e9);
    ll ans = 1;
    rep(i, n) {
        string s; cin>>s;
        int x; cin>>x;
        if(s == "ADD") {
            if(*Buy.rbegin() <= x and x <= *Sell.begin()) Mid.insert(x);
            else if(x < *Buy.rbegin()) Buy.insert(x);
            else if(*Sell.begin() < x) Sell.insert(x);
        }
        else {
            if(Mid.count(x)) {
                ans = (ans * 2) % MOD;
                Mid.erase(x);
            }
            else if(*Buy.rbegin() == x) Buy.erase(x);
            else if(*Sell.begin() == x) Sell.erase(x);
            else {
                cout<<"0\n";
                return 0;
            }

            for(auto u: Mid) {
                if(u < x) Buy.insert(u);
                else if(u > x) Sell.insert(u);
            }
            Mid.clear();
        }
    }
    cout<<((1LL + ll(Mid.size())) * ans) % MOD<<'\n';

    return 0;
}