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
        int n, k; cin>>n>>k;
        if(n == 1) {
            cout<<"1\n1\n";
            continue;
        }
        if(k == 1 or n == k) {
            cout<<"-1\n";
            continue;
        }
        cout<<3<<'\n';
        if(k % 2 == 1) {
            cout<<1<<' '<<k - 1<<' '<<k + 2<<'\n';        
        }
        else {
            cout<<1<<' '<<k<<' '<<k + 1<<'\n';
        }
    }





    return 0;
}