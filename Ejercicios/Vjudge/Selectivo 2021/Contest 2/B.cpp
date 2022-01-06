#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<ii> A(n);
    vector<ll> dif(n);
    rep(i,n) { cin>>A[i].ff>>A[i].ss; dif[i] = A[i].ff-A[i].ss; }
    sort(dif.begin(), dif.end(), greater<int>());
    ll suma=0; rep(i,n) suma+=A[i].ff;
    bool ans= 0;
    int mini= 100000000;
    if(suma<=m) mini = 0;
    rep(i,n){
        suma-=dif[i];
        if(suma <= m) mini=min(mini, i+1);
    }

    if(mini == 100000000) cout<<-1<<"\n";
    else cout<<mini<<"\n";





    return 0;
}