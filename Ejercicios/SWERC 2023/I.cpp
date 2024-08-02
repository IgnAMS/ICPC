#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define repx(i, a, b) for(int i = int(a); i < int(b); i++)
#define rep(i, n) repx(i, 0, n)
typedef vector<ll> vl;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;    
    vl A(n), B(m);
    
    ll espa = 0, espb = 0;
    rep(i, n) {
        cin>>A[i];
        espa += (1 + A[i]);
    }
    rep(i, m) {
        cin>>B[i];
        espb += (1 + B[i]);
    }

    // cout<<espa<<' '<<espb<<'\n';

    if(espa < espb) {
        cout<<"BOB\n";
    }
    else if(espa > espb) {
        cout<<"ALICE\n";
    }
    else cout<<"TIED\n";


    return 0;
}
