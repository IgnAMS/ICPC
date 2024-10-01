#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>k;
    rep(_, k){
        ll n, x, t; cin>>n>>x>>t;
        ll y = min(t / x, n-1);
        // cout<<y<<' '<<(n - y)<<'\n';
        cout<< y * (n - y) + y * (y - 1) / 2<<'\n'; 
    }




    return 0;
}