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
        int n, k; cin>>n>>k;
        vector<ll> A(n); rep(i, n) cin>>A[i];
        int agrupables = 0;
        vector<ll> B(n); rep(i,n) B[i] = A[i];
        sort(B.begin(), B.end());
        map<ll,ll> mapa; 
        rep(i, n - 1) mapa[B[i]] = B[i+1];
        rep(i, n-1) if(A[i] < A[i+1] and mapa.count(A[i]) and mapa[A[i]] == A[i+1]) agrupables++;
        if(n - agrupables <= k) cout<<"Yes\n";
        else cout<<"No\n";

    }

    return 0;
}