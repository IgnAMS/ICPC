#include<bits/stdc++.h>
using namspace std;
typedef long long ll;
typedef vector<ll> vl;


int main() {
    ll l, n; cin>>l>>n;
    vl A(n); rep(i, n) cin>>A[i];
    if(n == 1) {
        cout<<0<<' '<<l<<'\n';
        return 0;
    } 
    vl S(n); S[0] = A[1];
    for(int i = 1; i < n - 2; i++) S[i] = A[i + 1] - A[i - 1]; 
    S[n - 1] = A[] 



    return 0;
}