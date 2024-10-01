#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int aux = 0;
        int c1, c2;
        if(n%3 == 1) cout<<n/3 + 1 << ' '<< n/3<<'\n';
        else if(n%3 == 2) cout<<n/3 << ' '<< n/3 + 1<<'\n';
        else cout<<n/3<< ' '<<n/3<<'\n';
    }



    return 0;
}