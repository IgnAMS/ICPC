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
// g++ -O2 SubstringOrderI.cpp && time ./a.out <input.txt> output.txt

struct SA {
    int sz, l; 
    // C: indicador si es clone
    // Lk: link
    // Ilk: inverse links
    // L: maxlen of state
    // S: Size of state
    // F: first ocurrence of the state
    vl L, Lk, S, C, T, F, Count;
    vector<vl> N, Ilk;

    SA(string s, int n) : L(2 * n), Lk(2 * n), C(2 * n), F(2 * n), Count(2 * n, 0), N(2 * n, vl(26, -1)) {
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
    int size(int p) {
        if(S[p] != -1) return S[p];
        for(int i : Ilk[p]) S[p] += size(i);
        return S[p] += (1 - C[p]) + 1;
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

    ll all_occur(int u) {
        if(u == -1) return 0;
        if(Count[u] != -1) return Count[u];
        Count[u] = !C[u]; 
        for(int v: Ilk[u]) Count[u] += all_occur(v);
        return Count[u];
    }

    ll all_occur(string& s) { return all_occur(find(s)); }

    ll count(int u) {
        if(Count[u] > 0) return Count[u];
        Count[u] = 0;
        rep(c, 26) if(N[u][c] != -1) {
            Count[u] += count(N[u][c]);
        }
        return Count[u] += 1;
    }

    void kthless(int u, ll &cont, string& ans) {
        if(cont == 0) return;
        
        rep(c, 26) if(N[u][c] != -1) {
            if(cont > count(N[u][c])) cont -= count(N[u][c]);
            else {
                cont--;
                ans += char(c + 'a');
                kthless(N[u][c], cont, ans); 
                return;
            }
        }
        return;
    }



};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin>>s;
    int n = s.length();
    SA sa(s, n);

    string ans = "";
    ll k; cin>>k;
    sa.kthless(0, k, ans);
    cout<<ans<<'\n';
    


    return 0;
}