#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i, a, b) for(int i=a;i<b;i++)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll A[n]; rep(i,n) cin>>A[i];
    ll Acc[n + 1]; memset(Acc, 0, sizeof Acc);
    rep(i,n) Acc[i+1] += Acc[i]+A[0];
    





    return 0;
}