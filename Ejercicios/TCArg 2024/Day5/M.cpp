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

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

const int mxN = 3e5+5;
unordered_multiset<pll, hash_pair> XD;
unordered_set<pll, hash_pair> Px[mxN], Py[mxN], Original, Extension;
ll aux = 0;

void add(ll x, ll y) {
    Extension.insert({x, y});
    Original.insert({x, y});
    XD.insert({x, y});
    Px[x].insert({x, y});
    Py[y].insert({x, y});
    for(auto& [x1, y1]: Py[y]) if(x1 != x) {
        for(auto& [x11, y2]: Px[x1]) if(y2 != y) {
            // (x, y) = (x2, y1) 
            XD.insert({x, y2});
            Extension.insert({x, y2});
            Px[x].insert({x, y2});
            Py[y2].insert({x, y2});
        }
    }
    for(auto& [x1, y1]: Px[x]) if(y1 != y) {
        for(auto& [x2, y11]: Py[y1]) if(x2 != x) {
            // (x, y) = (x1, y2)
            XD.insert({x2, y});
            Extension.insert({x2, y});
            Px[x2].insert({x2, y});
            Py[y].insert({x2, y});
        }
    }
    for(auto& [x1, y2]: Px[x]) if(y2 != y) {
        for(auto& [x2, y1]: Py[y]) if(x2 != x1) {
            XD.insert({x2, y2});
            Extension.insert({x2, y2});
            Px[x2].insert({x2, y2});
            Py[y2].insert({x2, y2});
        }
    }
}


void erase(ll x, ll y) {
    XD.erase(XD.find({x, y}));
    if(!XD.count({x, y})) Extension.erase({x, y});
    Original.erase({x, y});
    Px[x].erase({x, y});
    Py[y].erase({x, y});
    for(auto& [x1, y1]: Py[y]) if(x1 != x) {
        for(auto& [x11, y2]: Px[x1]) if(y2 != y) {
            // (x, y) = (x2, y1) 
            XD.erase(XD.find({x, y2}));
            if(!XD.count({x, y2})) {
                Extension.erase({x, y2});
                // Extension.erase({x, y2});
                Px[x].erase({x, y2});
                Py[y2].erase({x, y2});
            }
        }
    }
    for(auto& [x1, y1]: Px[x]) if(y1 != y) {
        for(auto& [x2, y11]: Py[y1]) if(x2 != x) {
            // (x, y) = (x1, y2)
            XD.erase(XD.find({x2, y}));
            if(!XD.count({x2, y})) {
                Extension.erase({x2, y});
                // Extension.erase({x2, y});
                Px[x2].erase({x2, y});
                Py[y].erase({x2, y});
            }
        }
    }
    for(auto& [x1, y2]: Px[x]) if(y2 != y) {
        for(auto& [x2, y1]: Py[y]) if(x2 != x1) {
            XD.erase(XD.find({x2, y2}));
            if(!XD.count({x2, y2})) {
                Extension.erase({x2, y2});
                // Extension.erase({x2, y2});
                Px[x2].erase({x2, y2});
                Py[y2].erase({x2, y2});
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin>>q;
    rep(i, mxN) Px[i].reserve(sqrt(q)), Py[i].reserve(sqrt(q));
    Original.reserve(4 * q), Extension.reserve(4 * q);
    while(q--) {
        int x, y; cin>>x>>y;
        if(Original.count({x, y})) erase(x, y);
        else add(x, y);
        cout<<Extension.size()<<'\n';
        for(auto [a, b]: Extension) cout<<"("<<a<<", "<<b<<"), "; cout<<'\n';
        for(auto [a, b]: XD) cout<<"("<<a<<", "<<b<<"), "; cout<<'\n';
    }


    return 0;
}