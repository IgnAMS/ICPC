#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

int main(){
    int n, k; cin>>n>>k;
    vector<ii> A;
    int a,b;
    rep(i,n){
        cin>>a>>b;
        A.emplace_back(a,0);
        A.emplace_back(b,1);
    }
    sort(A.begin(),A.end());
    ll ans=0;
    ll open=0;
    rep(i,n){
        if(A[i].ss==0) open++;
        else open--;
        if(open==3) ans++;
        else if(open>3) ans+=open-1;
    }


    return 0;
}