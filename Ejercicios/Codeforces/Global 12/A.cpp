#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string line; cin>>line;
        string aux="";
        int cont=0;
        rep(i,n) {
            if(line[i]=='t') cont++;
            else aux+=line[i];
        }
        rep(i,cont) aux+='t';
        cout<<aux<<"\n";
    }



    return 0;
}