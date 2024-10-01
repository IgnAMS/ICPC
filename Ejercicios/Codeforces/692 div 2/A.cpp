#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; 
    while(t--){
        int n; cin>>n;
        string linea; cin>>linea;
        int i;
        for(i=n-1;i>=0 && linea[i]==')';i--) {}
        //cout<<i+1<<" "<<n-i-1<<"\n";
        if(i+1 >= n-i-1) cout<<"No\n";
        else cout<<"Yes\n";
        //tengo i+1 
    }



    return 0;
}