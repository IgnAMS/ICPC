#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<int> A;
int BS(int x){
    int l=0, r=A.size();
    int m;
    while(l<r){
        m = (l+r)/2;
        if(A[m]>=x) r=m;
        else l=m+1;
    }
    if(l==A.size()|| A[l]!=x) return -1;
    return l;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    A.resize(n); rep(i,n) cin>>A[i];
    int x;
    rep(i,m) { cin>>x; cout<<BS(x)<<"\n"; }



    return 0;
}