#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    vi A(n); rep(i, n) cin>>A[i];
    ll sq = sqrt(n);
    vector<vi> E;
    rep(i, m) {
        ll l, r; cin>>l>>r; l--, r--;
        E.push_back({l / sq, l, r, i});
    }
    sort(E.begin(), E.end(), [](auto const& a, auto const& b){
        return (a[0] == b[0]? a[2] < b[2]: a[0] < b[0]);
    });
    
    vi Ans(m);
    unordered_map<int, int> mp;
    rep(i, n) mp[A[i]] = 0;
    int l = 0, r = 0;
    ll ans = 0;
    mp[A[0]]++; 
    if(A[0] == 1) ans++;
    rep(i, m) {
        while(l < E[i][1]) { // saco el elemento en l
            if(mp[A[l]] == A[l]) ans--;
            mp[A[l]]--;
            if(mp[A[l]] == A[l]) ans++;
            l++;
        }
        while(l > E[i][1]) { // anado el elemento l + 1
            l--;
            if(mp[A[l]] == A[l]) ans--;
            mp[A[l]]++;
            if(mp[A[l]] == A[l]) ans++;
        }
        while(r < E[i][2]) { // anado el siguiente elemento
            r++;
            if(mp[A[r]] == A[r]) ans--;
            mp[A[r]]++;
            if(mp[A[r]] == A[r]) ans++;
        }
        while(r > E[i][2]) { // saco el elemento r
            if(mp[A[r]] == A[r]) ans--;
            mp[A[r]]--;
            if(mp[A[r]] == A[r]) ans++;
            r--;
        }
        Ans[E[i][3]] = ans;
    }
    rep(i, m) cout<<Ans[i]<<'\n';



    return 0;
}