#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

ll DP[101][10001];
ll A[101];
ll dp(ll i, ll x) {
    if(i == -1 and x == 0) return 1; 
    if(i == -1) return 0; 
    if(DP[i][x] != -1) return DP[i][x];
    DP[i][x] = dp(i - 1, x);
    if(A[i] <= x) DP[i][x] |= dp(i - 1, x - A[i]);
    return DP[i][x];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll suma = 0;
    rep(i, n) cin>>A[i], suma += A[i];
    rep(i, 101) rep(j, 10001) DP[i][j] = -1;

    if(dp(n - 1, suma / 2) == 0 or suma % 2 == 1) {
        cout<<"-1\n";
        return 0;
    }

    ll ind = n - 1, x = suma / 2;
    vl Alice, Bob;
    while(ind > -1) {
        // cout<<ind<<' '<<A[ind]<<' '<<DP[ind - 1][x - A[ind]]<<'\n';
        if(A[ind] <= x and dp(ind - 1, x - A[ind])) {
            Alice.pb(A[ind]);
            x -= A[ind];
        }
        else Bob.pb(A[ind]);
        ind--;
    } 


    suma = 0; 
    ll sumb = 0;
    sort(Alice.begin(), Alice.end());
    sort(Bob.begin(), Bob.end());


    ll i = 0, j = 0;
    vl Ans;
    while(i < Alice.size() or j < Bob.size()) {
        if(i < Alice.size() and j < Bob.size() and suma <= sumb) {
            Ans.pb(Alice[i]);
            suma += Alice[i];
            i++;
        }
        else if(i < Alice.size() and j < Bob.size() and suma > sumb) {
            Ans.pb(Bob[j]);
            sumb += Bob[j];
            j++;
        } 
        else if(i < Alice.size()) {
            Ans.pb(Alice[i]);
            suma += Alice[i];
            i++;
        }
        else {
            Ans.pb(Bob[j]);
            sumb += Bob[j];
            j++;
        }
    }
    for(auto u: Ans) cout<<u<<' '; cout<<'\n'; 

    return 0;
}