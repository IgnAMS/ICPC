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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        ll A[n]; 
        rep(i, n) cin>>A[i];
        ll B[n];
        rep(i, n) cin>>B[i];

        if(n == 1) {
            ll k2 = min((A[0] + B[0] - 1) / B[0], k);
        }
        
        // Caso bien feo: k = 1e9, n = 2e5, A[i] = 1e9, B[i] = 1
        // Me gustaria tomar todos los que estan en el rango A[i] - B[i] + 1 y sumarles 

        rep(i, n) {
            ll k = (A[i] + B[i] - 1) / B[i];
            repx(j, 1, k + 1) {
                cout<<j<<' '<<A[i] * j - j * (j - 1) / 2 * B[i]<<'\n';
            }
        }
        // Quiero elegir los elementos que mejor me sumen :)
        cout<<"\n\n";

    }


    return 0;
}