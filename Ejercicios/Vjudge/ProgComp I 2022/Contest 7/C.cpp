#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 C.cpp -o a && a <input.txt> output.txt
// g++ -O2 C.cpp && time ./a.out < input.txt > output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string D; cin>>D; int n; cin>>n;
    ll DP[1004][1004];
    ll P10[1004];
    P10[0] = 1 % n;
    repx(i, 1, 1003) P10[i] = (P10[i - 1] * 10) % n;
    rep(i, 1003) rep(j, 1003) DP[i][j] = 1003; 
    reverse(D.begin(), D.end());

    if(D.size() == 1 and (D[0] - '0' == n or D[0] == '?') and n < 10) {
        cout<<n<<'\n';
        return 0;
    }
    else if(D.size() == 1 and n < 10) {
        cout<<"*\n";
        return 0;
    } 
    else if(D.size() == 1 and n >= 10) {
        cout<<"*\n";
        return 0;
    }

    if(D[0] != '?') {
        ll mod = (D[0] - '0') % n;
        DP[0][mod] = D[0] - '0';
    }
    else {
        rep(j, 10) DP[0][j % n] = min(DP[0][j % n], j); // todos son posibles
    }
    
    repx(i, 1, D.size()) {
        if(D[i] != '?') {
            ll num = D[i] - '0';
            ll mod = (num * P10[i]) % n;
            rep(m1, n) if(DP[i - 1][m1] != 1003) {
                DP[i][(m1 + mod) % n] = num;
            }
        }
        else {
            repx(j, i == D.size() - 1, 10) {
                ll mod = (j * P10[i]) % n;
                rep(m1, n) if(DP[i - 1][m1] != 1003) {
                    DP[i][(m1 + mod) % n] = min(DP[i][(m1 + mod) % n], j);
                }
            }
        }
    }

    if(DP[D.size() - 1][0] != 1003) {
        string ans = "";
        ll x = DP[D.size() - 1][0], y = 0;
        ans += char(x + '0');
        // cout<<y<<'\n';
        for(int i = D.size() - 2; i >= 0; i--) {
            y = (y - x * P10[i + 1] + 10 * n) % n;
            // cout<<i<<' '<<y<<'\n';
            x = DP[i][y]; 
            ans += char(x + '0');
        }
        cout<<ans<<'\n';
    }
    else {
        cout<<"*\n";
    }
    




    return 0;
}