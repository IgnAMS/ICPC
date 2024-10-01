#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int a, b, c, m; cin>>a>>b>>c>>m;
        if(b > a and b > c) swap(a, b); 
        if(c > a and c > b) swap(a, c); // a siempre es el mayor 
        // cout<<a<<' '<<b<<' '<<c<<' '<<m<<'\n';
        if(a <= b + c + m + 1 and m <= a-1 +  b-1 + c-1) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}