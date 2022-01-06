#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    vector<ll> A(n);
    rep(i,0,n) cin>>A[i];
    sort(A.begin(),A.end(),greater<int>());
    //rep(i,0,n) cout<<A[i]<<" ";
    ll h=0;
    rep(i,0,n) if(A[i]>=h+1) h++;
    cout<<h<<"\n";




    return 0;
}