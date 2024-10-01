#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll h; 
        ll suma = 0;
        rep(i,n) { cin>>h; suma+=h; }
        if(suma < n) cout<<"1\n";
        else cout<<suma - n<<'\n';
    }



    return 0;
}