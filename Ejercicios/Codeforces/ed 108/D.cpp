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
    int n; cin>>n;
    ll A[n], B[n];
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i];
    
    ll L[n + 1];
    ll R[n + 1];
    L[0] = 0, R[n] = 0;
    rep(i, n) L[i + 1] = L[i] + A[i] * B[i];
    for(int i = n - 1; i >= 0; i--) R[i] = R[i + 1] + A[i] * B[i];
    
    ll ans = R[0];
    rep(i, n) {
        // suma impar
        ll l = i, r = i;
        ll curr = A[i] * B[i];
        while(l >= 1 and r + 1 < n) {
            l--, r++;
            curr += A[l] * B[r] + A[r] * B[l];
            ans = max(ans, L[l] + R[r + 1] + curr);
        }

        // suma par
        if(i + 1 < n) {
            l = i, r = i + 1;
            curr = A[i] * B[i + 1] + A[i + 1] * B[i];
            ans = max(ans, L[i] + R[r + 1] + curr);
            while(l >= 1 and r + 1 < n) {
                l--, r++;
                curr += A[l] * B[r] + A[r] * B[l];
                ans = max(ans, L[l] + R[r + 1] + curr);
            }
        }
    }
    cout<<ans<<'\n';


    return 0;
}