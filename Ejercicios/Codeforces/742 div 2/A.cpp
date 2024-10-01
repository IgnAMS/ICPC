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
        int n; cin>>n;
        string line; cin>>line;
        string aux = "";
        cerr<<"hola\n";
        rep(i, n) {
            if(line[i] == 'D') aux += "U";
            else if(line[i] == 'U') aux += "D";
            else if(line[i] == 'L') aux += "L";
            else if(line[i] == 'R') aux += "R";
        }
        cout<<aux<<'\n';
    }





    return 0;
}