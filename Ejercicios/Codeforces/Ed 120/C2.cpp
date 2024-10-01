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
    int t; cin>>t;
    while(t--) {
        ll n, k; cin>>n>>k;
        vi A(n); rep(i, n) cin>>A[i];
        sort(A.begin(), A.end());
        vi Acc(n + 1, 0); rep(i, n) Acc[i + 1] = Acc[i] + A[i];
        ll l = 0, r = 1e9 + n + 2;
        // peor de los casos 10^9 + n -> r = 10^12
        while(l < r) {
            ll m = (l + r) / 2;
            bool pos = 0;
            rep(i, min(m + 1, n)) { // cambio i cosas y bajo el mas pequeno en m - i
                if(A[0] - m + i + Acc[n - i] - A[0] + i * (A[0] - m + i) <= k) pos = 1;
            }
            if(pos) r = m;
            else l = m + 1; 
        }
        cout<<l<<'\n';
    }


    return 0;
}