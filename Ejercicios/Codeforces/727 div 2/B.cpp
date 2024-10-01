#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    string s; cin>>s;
    vector<ll> Acc(n+1, 0);
    rep(i, n){
        Acc[i+1] = Acc[i] + ll(s[i] - 'a' + 1);
    }
    rep(_, q){
        int a, b; cin>>a>>b;
        cout<<Acc[b] - Acc[a - 1]<<'\n';
    }




    return 0;
}