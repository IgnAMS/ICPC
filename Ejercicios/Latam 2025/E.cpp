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

const int mxN = 3e5+10;
struct ST {
    vl T;
    vl T2;
    int xd;
    ST(vl& A) {
        T2.resize(4 * A.size() + 10);
        T.assign(4 * A.size() + 10, 0);
        build(A, 0, A.size()-1, 0);
    }

    void build(vl&A, int l, int r, int u) {
        if(l == r) {
            T2[u] = A[l];
            return;
        }
        int m = (l + r) / 2;
        build(A, l, m, 2 * u + 1);
        build(A, m+1, r, 2 * u + 2);
        T2[u] = min(T2[2 * u + 1], T2[2 * u + 2]);
    }

    void update(int x, int v, int l, int r, int u) {
        if(l == r) {
            T[u] += v;
            T2[u] -= v;
            return;
        }
        int m = (l + r) / 2;
        if(x <= m) update(x, v, l, m, 2 * u + 1);
        else update(x, v, m + 1, r, 2 * u + 2);
        T[u] = T[2 * u + 1] + T[2 * u + 2];
        T2[u] = min(T2[2 * u + 1], T2[2 * u + 2] - T[2 * u + 1]);
    }

    void print(int l, int r, int u) {
        cerr<<"["<<l<<", "<<r<<"]: "<<T2[u]<<"\n";
        if(l == r) return;
        int m = (l+r)/2;
        print(l, m, 2 * u + 1);
        print(m+1, r, 2 * u + 2);
    }

    int query() {
        return T2[0];
    }
}; 



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<pll> ops(n);
    set<ll> S = {0};
    rep(i, n) {
        string s; cin>>s;
        int num = stoi(s.substr(1, s.size() - 1));
        if(s[0] == '+') 
            ops[i] = {1, num};
        else 
            ops[i] = {0, num};

        S.insert(num);
    }
    map<ll, ll> mp;
    for(auto u: S) mp[u] = mp.size();
    map<ll, ll> inv;
    for(auto [a, b]: mp) inv[b] = a;
    vl A = vl(S.begin(), S.end());

    ST st(A);


    int corte = 0;
    ll ans = 0;
    ll total = 0;
    n = A.size() - 1;
    // st.print(0, n, 0);
    // cerr<<"\n";

    for(auto [op, num]: ops) {
        if(op == 1) {
            total++;
            st.update(mp[num], 1, 0, n, 0);
        }
        else {
            total--;
            st.update(mp[num], -1, 0, n, 0);
        }
        // st.print(0, n, 0);
        // cerr<<"\n";
        cout<<total + st.query()<<" ";
    }
    cout<<"\n";

    return 0;
}