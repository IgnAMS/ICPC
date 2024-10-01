#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<ll> A(n); rep(i,n) cin>>A[i];
        sort(A.begin(), A.end(), greater<ll>());
        int ind = 1; 
        while(ind < n - 1 and A[ind] == A[ind-1]) ind++;
        ll ans = 0; 
        ll x = 0, y = 0;
        rep(i, 1) x += A[i];
        repx(i, 1, n) y += A[i];
        cout<<setprecision(7)<<fixed<<double(x)/double(1) + double(y) / double(n - 1)<<'\n';





    }






    return 0;
}