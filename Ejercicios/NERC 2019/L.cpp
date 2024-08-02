#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)

const int mxN = 1e3+5;
int n, m, k;
char ans[mxN][mxN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    rep(i, n){
        rep(j, m){
            ans[i][j] = '-';
        }
    }
    int ff = 0;
    int where = 0;
    rep(j, m){
        repx(i, where, k){
            ans[i][j] = s[ff++]; 
        }
        repx(i, where, k-1){
            if(ans[i][j] != ans[k-1][j]) where = i+1;
        }
    
    }
    rep(i, n){
        rep(j, m){
            if(ans[i][j] == '-') ans[i][j] = s[ff++];
            cout << ans[i][j];
        }
        cout << "\n";
    }
}