#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int a,b,c, d,e,f;
    while(cin>>a>>b>>c>>d>>e>>f) {
        cout<<max(0, d-a) + max(0, e-b) + max(0, f-c)<<"\n";
    }


    return 0;
}