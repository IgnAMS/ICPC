#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    int n; cin>>n;
    int A[n]; rep(i, n) cin>>A[i];
    bool imp[n], par[n]; rep(i,n) imp[i] = 0, par[i] = 0;
    rep(i, n) repx(j, i, n) if(A[i] % 2 and A[j] % 2 and (j - i + 1) % 2) {
        if(i == 0) imp[j] = 1;
        else{
            if(imp[i-1]) par[i] = 1;
            if(par[i-1]) imp[i] = 1;
        }
    }
    if(imp[n-1]) cout<<"Yes\n";
    else cout<<"No\n";






    return 0;
}