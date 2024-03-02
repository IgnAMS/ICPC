#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)

int main() {
    
    ll w, h, n;
    cin >> w >> h >> n;

    set<pll> H, V;
    multiset<ll> Hv, Vv;

    Hv.insert(w);
    Vv.insert(h);
    H.insert({0, w});
    V.insert({0, h});

    rep(i, n)
    {
        ll x;
        char c;
        cin >> c >> x;
        
        if(c == 'V')
        {
            auto it2 = prev(H.lower_bound({x,10000000}));
            auto it = *it2;
            //cout << it.first << " " << it.second << endl;
            pll p1 = {it.first, x};
            pll p2 = {x, it.second};

            Hv.erase(Hv.find(it.second - it.first));
            H.erase(it);
            Hv.insert(p1.second - p1.first);
            Hv.insert(p2.second - p2.first);
            H.insert(p1);
            H.insert(p2);
        }
        else{
            auto it2 = prev(V.lower_bound({x,10000000}));
            auto it = *it2;
            pll p1 = {it.first, x};
            pll p2 = {x, it.second};

            Vv.erase(Vv.find(it.second - it.first));
            V.erase(it);
            Vv.insert(p1.second - p1.first);
            Vv.insert(p2.second - p2.first);
            V.insert(p1);
            V.insert(p2);
        }
     
        cout << (*prev(Hv.end())) * (*prev(Vv.end())) << "\n";
    }

    return 0;

}


// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 G.cpp && time ./a.out <input.txt> output.txt
