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

struct SA {
    int sz, l, n; 
    // C: indicador si es clone
    // Lk: link
    // Ilk: inverse links
    // L: maxlen of state
    // S: Size of state
    // F: first ocurrence of the state
    // Count: DP for diff substrings from u
    // Count2: DP for all substrings from u
    vl L, Lk, S, C, T, F, Count, Count2;
    vector<vl> N, Ilk;

    SA(string s, int n) : n(n), L(2 * n), Lk(2 * n), C(2 * n), F(2 * n), Count(2 * n, 0), Count2(2 * n, -1), S(2 * n, -1), N(2 * n, vl(26, -1)) {
        l = L[0] = 0, Lk[0] = -1, sz = 1; 
        int p;
        for(char c : s) p = extend(c - 'a');
        Ilk.resize(sz); S.assign(sz, -1);
        rep(i, sz) if(i) Ilk[Lk[i]].pb(i);

        T.assign(sz, 0); 
        while(p != -1) T[p] = 1, p = Lk[p];
    }
    int extend(int c) {
        int cur = sz++, p = l; 
        C[cur] = 0, L[cur] = L[l] + 1, F[cur] = L[cur] - 1;
        while(p != -1 && N[p][c] == -1) N[p][c] = cur, p = Lk[p];
        if(p == -1) { 
            Lk[cur] = 0, l = cur;
            return cur;
        }
        int q = N[p][c];
        if(L[p] + 1 == L[q]) { Lk[cur] = q, l = cur; return cur; }
        int w = sz++; 
        C[w] = 1, L[w] = L[p] + 1, Lk[w] = Lk[q], N[w] = N[q];
        F[w] = F[q];
        while (p != -1 && N[p][c] == q) N[p][c] = w, p = Lk[p];
        Lk[q] = Lk[cur] = w, l = cur; return cur;
    }

    int find(string& s) {
        int p = 0;
        for(auto u: s) {
            int x = u - 'a';
            if(N[p][x] == -1) return -1;
            p = N[p][x];
        }
        return p;
    }

    void size(int u, int large, vector<int>& ans) {
        if(u == -1) return;

        // Occurrance at F[u] - large + 1 if it is not a clone
        if(!C[u]) ans.pb(F[u] - large + 1);
        for(int v: Ilk[u]) size(v, large, ans);
        return;
    }

    vector<int> size(string& s) { 
        vector<int> ans;
        size(find(s), s.length(), ans); 
        return ans;
    }

    ll count(int u) { // Number of diff substrings
        if(Count[u] > 0) return Count[u];
        Count[u] = 0;
        rep(c, 26) if(N[u][c] != -1) {
            Count[u] += count(N[u][c]);
        }
        return Count[u] += 1;
    }

};

struct Event {
    ll ind, open, large;
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // Necesito encontrar todas las apariciones en O(sum S_i)
    // Para eso podria usar un suffix automata
    int n, m; cin>>n>>m;
    string s; cin>>s;
    s = s + s + s;
    SA sa(s, 3 * n);
    
    vector<Event> Open[2 * n];
    vector<Event> Closed[2 * n], Active[2 * n];
    rep(i, m) {
        string aux; cin>>aux;
        vector<int> pos = sa.size(aux);
        ll large = aux.length();
        // for(auto u: pos) cout<<u<<' '; cout<<'\n';   
        for(auto u: pos) {
            // cerr<<u<<' '<<u + large - 1<<' '<<n + u<<'\n';
            // what happens if n + u < u + large - 1
            // n < large - 1 
            if(u < 2 * n) Open[u].pb({u, 1, large});
            if(u + large - 1 < 2 * n) Active[u + large - 1].pb({u, 1, large});
            if(n >= large - 1 and n + u < 2 * n) Closed[n + u].pb({n + u, 0, large});
        }
    }


    multiset<ll> initiate, active;
    set<ll> inactive;
    ll gap = 0;
    rep(i, n) {
        for(auto e: Open[i]) {
            initiate.insert(i);
        }
        
        for(auto e: Active[i]) {
            initiate.erase(initiate.find(e.ind));
            active.insert(e.large);
        }
        
        gap++;
    }

    ll ans = (active.empty()? 0: *active.rbegin());
    ans = (initiate.empty()? ans: max(ans, *initiate.rbegin() - gap));
    repx(i, n, 2 * n) {
        for(auto e: Open[i]) {
            initiate.insert(i);
        }
        for(auto e: Active[i]) {
            initiate.erase(initiate.find(e.ind));
            active.insert(e.large);
        }
        
        for(auto u: Closed[i]) {
            active.erase(active.find(u.large));
            inactive.insert(u.large + gap);
        }
        
        gap++;

        cout<<i<<'\n';
        for(auto u: initiate) cout<<gap - u<<' '; cout<<'\n';
        
        ll mxinactive = (inactive.empty()? 0: *inactive.rbegin() - gap);
        ll mxactive = (active.empty()? 0: *active.rbegin());
        ll mxinitiate = (initiate.empty()? 0: gap - *initiate.begin());

        ans = min(
            ans,
            max({mxinactive, mxactive, mxinitiate})
        );
    }
    cout<<ans<<'\n';


    return 0;
}