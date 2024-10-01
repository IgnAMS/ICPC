#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
#define ff first
#define ss second



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int c, d; cin>>c>>d;
        if(c == 0 and d == 0) cout<<"0\n";
        else if(c == d) cout<<"1\n";
        else if(abs(c - d) % 2 != 0) cout<<"-1\n";
        else cout<<"2\n";


    }





    return 0;
}