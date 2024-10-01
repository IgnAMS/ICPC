#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second



int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int x = n/2 - 1;
        if(n > 1){
            rep(i, x) cout<<'a';
            cout<<'b';
            rep(i, x+1) cout<<'a';
        }
        if(n%2) cout<<'c';
        cout<<'\n';
    }






    return 0;
}