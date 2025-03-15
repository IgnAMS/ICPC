#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define pb push_back
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    string S[n];
    
    pll A;
    rep(i, n) {
        cin>>S[i];
        rep(j, m) if(S[i][j] == 'A') A = {i, j};
    }
    
    vector<array<ll, 3>> L; // [j, up, down]

    ll up = 0, down = n - 1;
    for(int i = A.ff - 1; i >= 0; i--) {
        if(S[i][A.ss] != '.') {
            up = i + 1;
            break;
        }
    }
    for(int i = A.ff + 1; i < n; i++) {
        if(S[i][A.ss] != '.') {
            down = i - 1;
            break;
        }
    }
    // cout<<A.ff<<' '<<A.ss<<'\n';
    ll og_up = up, og_down = down;
    L.pb({A.ss, up, down});

    for(int j = A.ss - 1; j >= 0; j--) {
        if(S[A.ff][j] != '.') break;
        for(ll i = A.ff - 1; i >= 0; i--) {
            if(S[i][j] != '.') up = max(up, i + 1);
        }
        for(ll i = A.ff + 1; i < n; i++) {
            if(S[i][j] != '.') down = min(down, i - 1);
        }
        L.pb({j, up, down});
    }

    
    up = og_up, down = og_down;
    for(int j = A.ss + 1; j < m; j++) {
        if(S[A.ff][j] != '.') break;
        for(ll i = A.ff - 1; i >= 0; i--) {
            if(S[i][j] != '.') up = max(up, i + 1);
        }
        for(ll i = A.ff + 1; i < n; i++) {
            if(S[i][j] != '.') down = min(down, i - 1);
        }
        L.pb({j, up, down});
    }

    ll area = 0, best[4];
    // best = {{i1, j1}, {i2, j2}}
    for(auto x1: L) {
        for(auto x2: L) {
            // Estan en lados cruzados
            if(x1[0] <= A.ss and A.ss <= x2[0]) {
                ll u = max(x1[1], x2[1]);
                ll d = min(x1[2], x2[2]);
                ll curr = (x2[0] - x1[0] + 1) * (d - u + 1);
                // cout<<curr<<' '<<u<<' '<<x1[0]<<' '<<d<<' '<<x2[0]<<'\n';
                if(curr > area) {
                    area = curr;
                    best[0] = u,
                    best[1] = x1[0],
                    best[2] = d,
                    best[3] = x2[0];
                }
            }
        }
    }
    repx(i, best[0], best[2] + 1) repx(j, best[1], best[3] + 1) {
        if(S[i][j] == '.') S[i][j] = 'a';
    }

    // rep(i, n) cout<<S[i]<<'\n';
    // cout<<'\n';

    // Tengo a lo mas 26 letras

    rep(i, n) rep(j, m) if('B' <= S[i][j] and S[i][j] <= 'Z') {
        // cout<<"entre con "<<S[i][j]<<'\n';
        ll left = 0;
        for(int b = j - 1; b >= 0; b--) {
            if(S[i][b] != '.') {
                left = b + 1;
                break;
            }
        }
        
        ll up = 0;
        for(int a = i - 1; a >= 0; a--) {
            repx(b, left, j + 1) if(S[a][b] != '.') {
                up = a + 1;
                break;
            }
            if(up != 0) break;
        }
        
        ll right = m - 1;
        repx(b, j + 1, m) {
            repx(a, up, i + 1) if(S[a][b] != '.') {
                right = b - 1;
                break;
            }
            if(right != m - 1) break;
        }
    
        ll down = n - 1;
        repx(a, i + 1, n) {
            repx(b, left, right + 1) if(S[a][b] != '.') {
                down = a - 1;
                break;
            }
            if(down != n - 1) break;
        }
        repx(a, up, down + 1) repx(b, left, right + 1) if(S[a][b] == '.') 
            S[a][b] = S[i][j] + ('a' - 'A');
    }
    
    rep(i, n) cout<<S[i]<<'\n';

    return 0;
}