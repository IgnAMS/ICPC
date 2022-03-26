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
    ll n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    vector<vi> E;
    rep(i, n - 1) E.push_back({A[i + 1] - A[i], 0, 0});
    
    ll q; cin>>q;
    rep(i, q) {
        ll l, r; cin>>l>>r;
        E.push_back({r - l + 1, 1, i});
    }
    
    ll curr = 0;
    ll l = 0, inactive = 0;
    vi Ans(q, 0);
    sort(E.begin(), E.end());
    rep(i, E.size()) {
        curr += (n - inactive) * (E[i][0] - l);
        if(E[i][1] == 0) inactive++;
        else Ans[E[i][2]] = curr;
        l = E[i][0];
    }
    rep(i, q) cout<<Ans[i]<<" \n"[i == q - 1];




    return 0;
}