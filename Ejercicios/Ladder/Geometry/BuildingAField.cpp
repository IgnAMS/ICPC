#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;
typedef vector<ll> vl;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll A[n]; 
    
    set<ll> S;
    ll suma = 0;
    rep(i,n) {
        cin>>A[i];
        suma += A[i];
        S.insert(suma);
    }

    if(suma % 2) {
        cout<<"N\n";
        return 0;
    }
    
    ll cont = 0;
    for(auto u: S) {
        // cout<<u<<' '<<u + suma / 2<<'\n';
        if(S.count(u + suma / 2)) cont++;
    }
    cout<<(cont >= 2? "Y": "N")<<'\n';

    return 0;
}