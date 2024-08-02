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

    ll size(int u) {
        if(u == -1) return 0;
        if(S[u] != -1) return S[u];
        // Occurrance at F[u] - large + 1 if it is not a clone
        S[u] = !C[u]; 
        for(int v: Ilk[u]) S[u] += size(v);
        return S[u];
    }

    ll size(string& s) { return size(find(s)); }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s1, s2;
    cin>>s1>>s2;
    int n1 = s1.length(), n2 = s2.length();
    SA sa1(s1, n1), sa2(s2, n2);
    
    int ans = 1e4;
    rep(i, n1) {
        int u1 = 0, u2 = 0;
        repx(j, i, n1) {
            if(sa1.N[u1][s1[j] - 'a'] != -1) u1 = sa1.N[u1][s1[j] - 'a'];
            else break;
            if(sa2.N[u2][s1[j] - 'a'] != -1) u2 = sa2.N[u2][s1[j] - 'a'];
            else break;

            int largo = j - i + 1;
            if(sa1.size(u1) == 1 and sa2.size(u2) == 1) ans = min(ans, largo);
        }
    }
    if(ans == 1e4) cout<<"-1\n";
    else cout<<ans<<'\n';

    return 0;
}