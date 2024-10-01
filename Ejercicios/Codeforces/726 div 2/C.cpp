#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vector<ll> A(n); rep(i,n) cin>>A[i];
        sort(A.begin(), A.end());
        ll mini = 1e10;
        ll i1, i2;
        rep(i,n-1){
            if(A[i+1] - A[i] < mini) { i1 = i, i2 = i+1; mini = A[i+1] - A[i]; }
        }
        cout<<A[i1]<<" ";
        // rep(i,n) if(i != i1 and i != i2) cout<<A[i]<<" ";
        repx(i, i2+1, n) cout<<A[i]<<" ";
        repx(i, 0, i1) cout<<A[i]<<" ";
        cout<<A[i2]<<'\n';
    }



    return 0;
}