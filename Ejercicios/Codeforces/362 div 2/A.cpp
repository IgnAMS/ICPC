#pragma GCC optimize("Ofast")
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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t, x, s; cin>>t>>s>>x;
    if(t == x) cout<<"YES\n";
    else if(x - t > 0 and (x - t) % s == 0) cout<<"YES\n";
    else if(x - t - 1 > 0 and (x - t - 1) % s == 0) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}