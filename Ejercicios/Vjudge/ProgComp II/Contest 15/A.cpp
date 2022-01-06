#include<bits/stdc++.h>
using namespace std;
typedef pair<string,int> si;
#define ff first
#define ss second
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n; cin>>n;
    vector<si> A(n);
    rep(i,n) cin>>A[i].ff>>A[i].ss;

    sort(A.begin(),A.end(),[&](const si& a, const si& b){
        if(a.ss==b.ss) return a.ff < b.ff;
        return a.ss < b.ss;
    });

    return 0;
}
