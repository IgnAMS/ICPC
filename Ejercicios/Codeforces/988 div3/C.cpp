#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        if(n <= 4) {
            cout<<"-1\n";
            continue;
        }
        for(int i = 1; i <= n; i += 2) if(i != 5) cout<<i<<' ';
        cout<<5<<' '; 
        cout<<4<<' '; 
        for(int i = 2; i <= n; i += 2) if(i != 4) cout<<i<<' '; 
        cout<<'\n';
    }


    return 0;
}