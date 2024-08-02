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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    ll A[n + 2]; rep(i, n) cin>>A[i + 1];
    A[0] = 0, A[n + 1] = m;

    vl Acc(n + 3, 0);
    for(int i = n; i >= 0; i--) {
        Acc[i] = Acc[i + 1];
        if((i + 1) & 1) Acc[i] += A[i + 1] - A[i];
        // cout<<A[i]<<' '<<Acc[i]<<'\n'; 
    }
    // cout<<"la respuesta inicial es "<<Acc[0]<<'\n';
    ll ans = Acc[0];
    ll acc = 0;
    for(int i = 0; i <= n; i++) {
        // cout<<A[i]<<' '<<Acc[i + 1]<<'\n'; 
        if(i & 1) acc += A[i] - A[i - 1];
        if(A[i + 1] != A[i] + 1) {
            // Primer caso: Invierto algo que me dara positivo 
            // cout<<"Estoy en "<<A[i]<<'\n';
            // cout<<"acc: "<<acc<<", nuevo: "<<1<<", revierto el intervalo "<<(m - A[i + 1] - Acc[i + 1])<<'\n';
            // cout<<"acc: "<<acc<<", nuevo: "<<A[i + 1] - 1 - A[i]<<", revierto el intervalo "<<(m - A[i + 1] - Acc[i + 1])<<'\n';
            ans = max(ans, acc + 1 + (m - A[i + 1] - Acc[i + 1]));
            ans = max(ans, acc + (A[i + 1] - 1 - A[i]) + (m - A[i + 1] - Acc[i + 1]));
        }
        // cout<<'\n';
    }
    cout<<ans<<'\n';






    return 0;
}