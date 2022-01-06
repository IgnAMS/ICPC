#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

ll n, w, l;
vector<int> A;

bool check(ll d){
    int i=1;
    int trenes=1;
    int ind=0;
    while(ind < w){
        if(A[ind] > i+d-1) { trenes++; i=A[ind]; }
        while(ind < w && A[ind] <= i+d-1) ind++;
        if(i+d-1 < n) { trenes++; i+=d; }
    }
    return (trenes<=l);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>w>>l; A.resize(w);
        rep(i,w) cin>>A[i];
        sort(A.begin(),A.end());
        int l=1, r=n+1, m;
        //cerr<<"next\n";
        while(l<r){
            m=(l+r)/2;
            //cerr<<m<<" "<<check(m)<<"\n";
            if(check(m)) r=m;
            else l=m+1;
        }
        cout<<l<<"\n";

    }


    return 0;
}