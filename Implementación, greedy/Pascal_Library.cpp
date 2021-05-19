#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int n,m;
    while(cin>>n>>m && n) {
        bool ans=0;
        int x[m];
        rep(i,n) { 
            bool flag=1; 
            rep(j,m) { cin>>x[j]; flag &= x[j]; }
            ans |= flag; 
        }
        if(ans) cout<<"yes\n";
        else cout<<"no\n";
    }

    
    return 0;
}