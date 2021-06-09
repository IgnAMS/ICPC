#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, b;
    cerr<<"xd\n";
    while(cin>>n>>b && n){
        cerr<<n<<"\n";
        int B[b]; rep(i,b) cin>>B[i];
        set<int> S;
        rep(i,b) rep(j,b) S.insert(abs(B[i]-B[j]));
        bool flag = 1;
        //for(auto& u: S) cout<<u<<" "; cout<<"\n";
        rep(i,n + 1) if(!S.count(i)) flag=0;
        if(flag) cout<<"Y\n";
        else cout<<"N\n";
    }


    return 0;
}