#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<set>
#include<map>
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

const int mxN = 3e5;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pll> ops(n);
    set<ll> S;
    rep(i, n) {
        string s; cin>>s;
        int num = stoi(s.substr(1, s.size() - 1));
        if(s[0] == '+') 
            ops[i] = {1, num};
        else 
            ops[i] = {0, num};

        S.insert(num);
    }
    
    int corte = 0;
    ll ans = 1;
    ll total = 0;
    multiset<ll> L = {0}, R = {1000000005};
    for(auto [op, num]: ops) {
        if(op == 1) {
            total++;
            if(num > *L.rbegin()) {
                ans++;
                R.insert(num);
                cerr<<R.size()<<" "<<R.count(*R.begin())<<" "<<*R.begin()<<": "<<R.size() - R.count(*R.begin()) + *R.begin()<<"\n";
                if(ans < R.size() - R.count(*R.begin()) + *R.begin()) {
                    ans = R.size() - R.count(*R.begin()) + *R.begin();
                    rep(i, R.count(*R.begin())) L.insert(*R.begin());
                    R.erase(*R.begin());
                }
            }
        }
        else {
            total--;
            R.erase(R.find(num));
            // num > corte -> debo sacar uno menos
            if(num > corte) ans--;

            // debo ver si me cambia el corte
            else {
                // tal vez debo tomar algo de la izquierda y llevarlo a la derecha
                while(true) {
                    ll cand = R.size() + L.count(*L.rbegin()) + *next(L.rbegin());
                    if(cand >= ans) break;
                    rep(i, L.count(*L.begin())) R.insert(*L.rbegin());
                    L.erase(*L.rbegin());
                    ans = cand;
                }
            }
        }
        // cerr<<total<<" "<<corte<<" "<<ans<<"\n";
        cout<<ans - 1<<" ";
    }
    cout<<"\n";

    







    return 0;
}