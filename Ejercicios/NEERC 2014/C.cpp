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
// g++ -O2 C.cpp && time ./a.out <input.txt> output.txt

const int mxN = 3e5+5;
map<string, string> Props[mxN];
vl G[mxN];



int A[mxN], H[mxN], D[mxN], R[mxN], P[mxN], Inv[mxN];
map<string, vl> List;

class HLD {
    int dfs(int u) {
        int ans = 1, M = 0, s;
        for (int v : G[u]) if (v != A[u]) {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(v), ans += s;
            if(s > M) H[u] = v, M = s;
        }
        return ans;
    }

public:
    HLD(int n) {
        rep(i, n) H[i] = -1;
        A[0] = -1, D[0] = 0;
        
        dfs(0);

        int p = 0;
        rep(i, n) if (A[i] == -1 or H[A[i]] != i) {
            for (int j = i; j != -1; j = H[j]) {
                for(auto& [key, val]: Props[j]) List[key].pb(p); 
                R[j] = i, Inv[p] = j, P[j] = p;
                p++;
            }
        }
    }

    string query(int v, string &key) {
        while(R[v] != 0) {
            auto it = upper_bound(List[key].begin(), List[key].end(), P[v]);
            if(it != List[key].begin()) {
                it--;
                if(P[R[v]] <= *it) return Props[Inv[*it]][key];
            }
            v = A[R[v]];
        }
        auto it = upper_bound(List[key].begin(), List[key].end(), P[v]);
        if(it != List[key].begin()) {
            it--;
            if(P[R[v]] <= *it) return Props[Inv[*it]][key];
        }
        return "N/A";
    }
};

ll to_ll(string& s) {
    ll base = 1, ans = 0;
    for(auto& c: s) {
        if('A' <= c and c <= 'Z') ans += base * ll(c - 'A' + 27);
        else ans += base * ll(c - 'a' + 1); 
        base *= 54;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n) {
        int p, k; cin>>p>>k;
        G[p].pb(i + 1);
        rep(_, k) {
            string keyval; cin>>keyval;
            bool bool_key = 1;
            string key = "", val = "";
            for(auto& c: keyval) {
                if(c == '=') bool_key = 0;
                else if(bool_key) key += c;
                else val += c;
            }
            Props[i + 1][key] = val;
        }
    }

    HLD hld(n + 1);

    int q; cin>>q;
    rep(i, q) {
        int c; 
        string key; cin>>c>>key;
        cout<<hld.query(c, key)<<endl;
    }

    return 0;
}