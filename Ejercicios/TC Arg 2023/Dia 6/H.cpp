#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second


int main() {
    int n, m; cin>>n>>m;
    vl A(n); rep(i, n) cin>>A[i];
    vector<pll> E;
    vl F(m + 1, 0);
    rep(i, n - 1) {
        if(abs(A[i] - A[i + 1]) >= 2) {
            E.push_back({min(A[i], A[i+1]) + 1, -1});
            E.push_back({max(A[i], A[i+1]) - 1, 1});
        }
        F[A[i]]++; 
    }
    F[A[n-1]]++;
    if(abs(A[n-1] - A[0]) >= 2) {
        E.push_back({min(A[n-1], A[0]) + 1, -1});
        E.push_back({max(A[n-1], A[0]) - 1, 1});
    }

    sort(E.begin(), E.end());

    ll l = 0;
    ll curr = 0;
    repx(i, 1, m + 1) {
        while(l < E.size() and E[l].ff == i and E[l].ss == -1) {
            curr += 1;
            l++;
        }
        if(i > 0) {
            cout<<"curr: "<<curr<<'\n';
        }
        if(!F[i]) cout<<"-1 ";
        else cout<<n - F[i] + curr<<' ';
        while(l < E.size() and E[l].ff == i and E[l].ss == 1) {
            curr -= 1;
            l++;
        }
    }


    return 0;
}