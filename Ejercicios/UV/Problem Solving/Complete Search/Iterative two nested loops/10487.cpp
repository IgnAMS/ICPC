#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int,int> ii;
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    int cas=0;
    while(cin>>n && n && ++cas){
        ll A[n]; rep(i,n) cin>>A[i];
        int m; cin>>m;
        cout<<"Case "<<cas<<":\n";
        while(m--){
            ll q; cin>>q;
            ll ans=0;
            ll mini=1e10;
            rep(i,n) rep(j,n) if(i!=j)
                if(abs(q-A[i]-A[j]) < mini) { 
                    mini = abs(q-A[i]-A[j]);
                    ans=A[i]+A[j];
                }
            cout<<"Closest sum to "<<q<<" is "<<ans<<".\n";
            
        }
    }



    return 0;
}