#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, m, sx, sy, d; cin>>n>>m>>sx>>sy>>d;
        if(sx + d >= n and sy + d >= m) cout<<"-1\n";
        else if(sx - d <= 1 and sy - d <= 1) cout<<"-1\n";
        else if(sx - d <= 1 and sx + d >= n) cout<<"-1\n";
        else if(sy - d <= 1 and sy + d >= m) cout<<"-1\n";
        else cout<<n + m - 2<<'\n'; 





    }


    return 0;
}