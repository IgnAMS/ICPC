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

ll DP[2506][27];
int n;
vl A;
ll INF = 10000000;
ll dp(ll i, ll letter) {
    if(A[i] != -1 and letter != A[i]) return -INF;
    if(i == 0) return 0;
    
    if(DP[i][letter] != -1) return DP[i][letter];

    DP[i][letter] = -INF;
    rep(c, n) {
        DP[i][letter] = max(DP[i][letter], dp(i - 1, c) + (letter != c));
    }
    return DP[i][letter];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    string s; cin>>s;
    rep(i, s.size()) {
        if(s[i] == '.') A.pb(-1);
        else A.pb(s[i] - 'A');
    }

    ll letter = 0;
    rep(i, 2506) rep(j, 27) DP[i][j] = -1;

    rep(i, n) {
        if(dp(s.size() - 1, i) > dp(s.size() - 1, letter)) letter = i;
    }
    // cout<<dp(s.size() - 1, letter)<<'\n';
    string ans = ""; 
    ans += char('A' + letter);
    int ind = s.size() - 1;
    while(ind >= 1) {
        // cout<<"con "<<ind<<' '<<letter<<" tengo dp "<<dp(ind, letter)<<'\n';
        rep(i, n) {
            // cout<<ind - 1<<' '<<i<<" tiene dp "<<dp(ind - 1, i) + (letter != i)<<'\n';
            if(dp(ind - 1, i) + (letter != i) == dp(ind, letter)) {
                ans += char('A' + i);
                ind--;
                letter = i;
                break;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<ans<<'\n';


    return 0;
}