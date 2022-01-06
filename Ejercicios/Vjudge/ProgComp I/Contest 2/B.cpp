#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        int l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
        if(l1==l2 && r1==r2) cout<<l1<<" "<<r1<<"\n";
        else if(l1!=l2) cout<<l1<<" "<<l2<<"\n";
        else cout<<r1<<" "<<r2<<"\n"; 
    }




    return 0;
}