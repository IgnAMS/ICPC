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

ll A[200001];
int n; 

ll calc(int i) {
    ll ans = 0;
    if(i > 0 and A[i] == A[i - 1]) ans++;
    if(i > 0 and A[n - i] == A[n - i - 1]) ans++;
    if(A[i] == A[i + 1]) ans++;
    if(A[n - i - 1] == A[n - i - 2]) ans++;

    return ans; 
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        rep(i, n) cin>>A[i];

        ll ans = 0;
        rep(i, n - 1) ans += A[i] == A[i + 1];

        rep(i, n / 2) {
            if(A[i] == A[n - i - 1]) continue;
            ll d1 = calc(i);
            swap(A[i], A[n - i - 1]);
            ll d2 = calc(i);
            swap(A[i], A[n - i - 1]);
                 
            if(d2 < d1) {
                swap(A[i], A[n - i - 1]);
                ans += d2 - d1;
            }
        }
        cout<<ans<<'\n';
    }



    return 0;
}