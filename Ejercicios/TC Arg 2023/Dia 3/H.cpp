#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ll long long
#define vl vector<ll>
#define ff first
#define ss second
#define pb push_back

const int mxN = 3e5+5;

struct AC{
    ll c = 0, ec = 0, M, A, af = -1;
    vector<vl> N, G; 
    vl L, E, DP;   

    AC(ll M, ll A) : M(M), A(A), N(M, vl(A, 0)), G(M, vl()), E(M, 0), L(M, 0), DP(M, 0) {}
    ll add(string& s){
        af++;
        ll p = 0;
        for(char l : s){
            int t = l-'a';
            if(!N[p][t]) N[p][t] = ++c;
            p = N[p][t];
        }
        // En el nodo terminal le aumento en 1
        DP[p] += 1;
        return p;
    }
    void init() {
        queue<int> q; q.push(0); L[0] = -1;
        while(q.size()){
            int p = q.front(); q.pop();
            for(int c = 0; c < A; c++){
                int u = N[p][c]; if(!u) continue;
                L[u] = L[p] == -1 ? 0 : N[L[p]][c], q.push(u);
                if(L[u] != -1) {
                    DP[u] += DP[L[u]];
                }
                G[L[u]].push_back(u);
            }
            if(p) for(int c = 0; c<A; c++) if(!N[p][c]) N[p][c] = N[L[p]][c];
        }
    }
    ll search_words(string& text){
        int u = 0;
        ll ans = 0;
        rep(i, (int)text.size()){
            ll c = text[i] - 'a';
            if(N[u][c]) {
                u = N[u][c];
                ans += DP[u];
            }
            else {
                while(L[u] != -1 and !N[L[u]][c]) u = N[L[u]][c];
                ans += DP[u];
            }
        }
        return ans;
    }
};

int main() {
    int n, m;
    cin >> n >> m; 
    AC ac(n*100, 26);
    vector<string> a(n);
    rep(i, n){
        cin >> a[i];
        ac.add(a[i]);
    }
    ac.init();
    string S; cin>>S;
    ll curr = ac.search_words(S);
    cout<<curr<<'\n';
    rep(i, m) {
        ll p; cin>>p; p--;
        char c; cin>>c;
        string qresta = "", qsuma = "";
        for(int i = max(0LL, p - 100); i < min((ll)S.length(), p + 100); i++) {
            qresta += S[i];
            if(i != p) qsuma += S[i];
            else qsuma += c;
        }
        curr = curr - ac.search_words(qresta) + ac.search_words(qsuma);
        cout<<curr<<'\n';
        S[p] = c;
    }
}