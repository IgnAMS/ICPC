#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k, x; cin>>n>>k>>x;
    vector<ll> A(n); rep(i,n) cin>>A[i];
    sort(A.begin(), A.end());
    vector<ll> dif;
    rep(i, n-1) {
        if(A[i+1] - A[i] > x) dif.push_back(A[i+1] - A[i]);
    }
    sort(dif.begin(), dif.end());
    ll j = 0, desc = 0;
    while(j < dif.size() and k >= (dif[j] + 2 * x - 1) / (2 * x)){
        desc++; 
        k -= (dif[j++] + 2 * x - 1) / (2 * x);
    }
    cout<<dif.size() + 1 - desc<<'\n';





    return 0;
}