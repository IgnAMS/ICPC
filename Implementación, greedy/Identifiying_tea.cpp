#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i=a;i<b;i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, A[5];
    while(cin>>t) {
        int ans=0;
        rep(i,5) { cin>>A[i]; if(A[i]==t) ans++; }
        cout<<ans<<"\n";
    }



    return 0;
}