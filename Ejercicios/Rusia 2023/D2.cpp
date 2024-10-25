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
        for(char c : s) p = extend(c - 'A');
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
            int x = u - 'A';
            if(N[p][x] == -1) return -1;
            p = N[p][x];
        }
        return p;
    }

    ll size(int u) {
        if(u == -1) return 0;
        if(S[u] != -1) return S[u];
        // Occurrance at F[u] - large + 1 if it is not a clone
        S[u] = !C[u]; 
        for(int v: Ilk[u]) S[u] += size(v);
        return S[u];
    }

    ll size(string& s) { return size(find(s)); }

    ll count(int u) { // Number of diff substrings
        if(Count[u] > 0) return Count[u];
        Count[u] = 0;
        rep(c, 26) if(N[u][c] != -1) {
            Count[u] += count(N[u][c]);
        }
        return Count[u] += 1;
    }

    ll count2(int u) {
        if(Count2[u] != -1) return Count2[u];
        Count2[u] = size(u);
        rep(c, 26) if(N[u][c] != -1) {
            Count2[u] += count2(N[u][c]);
        }
        return Count2[u];
    }

    void kthless(int u, ll &cont, string& ans) {
        if(cont <= 0) return;
        rep(c, 26) if(N[u][c] != -1) {
            // change to count(N[u][c]) for diff substrs
            if(cont > count2(N[u][c])) cont -= count2(N[u][c]); 
            else {
                // change to cont-- for diff substrs
                cont -= size(N[u][c]); 
                ans += char(c + 'A');
                kthless(N[u][c], cont, ans); 
                return;
            }
        }
        return;
    }
    
    void count_substrs() {
        vector<ll> Open[n + 1];
        vector<ll> Closed[n + 1];
        repx(i, 1, sz) {
            ll val = size(i);
            // change 1 to val for not different substrs
            Open[L[Lk[i]]].pb(1); 
            Closed[L[i]].pb(1);
        }
        ll cont = 0;
        rep(i, n + 1) {
            if(i) cout<<cont<<' ';
            for(auto x: Open[i]) cont += x;
            for(auto x: Closed[i]) cont -= x; 
        }
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    string s2 = "";
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == 'A') s2 += 'T';
        if(s[i] == 'T') s2 += 'A';
        if(s[i] == 'G') s2 += 'C';
        if(s[i] == 'C') s2 += 'G';
    }
    // cout<<s2<<'\n';
    
    SA sa(s, n);
    ll u = 0, curr = 0;
    pll best = {-1, -2};
    rep(j, n) {
        while(u != 0 and sa.N[u][s2[j] - 'A'] == -1) {
            u = sa.Lk[u], curr = sa.L[u];
        }
        if(sa.N[u][s2[j] - 'A'] == -1) continue;
        u = sa.N[u][s2[j] - 'A'], curr++;
        if(curr >= best.ss - best.ff + 1) {
            // cout<<"rango "<<j - curr + 1<<' '<<j<<'\n';
            best = {j - curr + 1, j};
        }
        // cout<<u<<' '<<curr<<'\n';
    }
    cout<<best.ss - best.ff + 1<<'\n';
    if(best.ff != -1) cout<<s2.substr(best.ff, (best.ss - best.ff) + 1)<<'\n';



    return 0;
}