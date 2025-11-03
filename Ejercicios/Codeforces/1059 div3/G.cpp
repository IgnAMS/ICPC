#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
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

void solve() {
    int n; cin>>n;
    if(n == 2) {
        cout<<"-1\n";
        return;
    }
    if(n == 3) {
        cout<<"1 3\n2 3\n";
    }
    if(n == 4) {
        cout<<"1 2\n3 1\n4 1\n";
    }
    if(n == 5) {
        cout<<"5 1\n4 3\n3 2\n2 1\n";
    }
    if(n == 6) {
        cout<<"6 2\n5 3\n4 1\n3 1\n2 1\n";
    }
    if(n <= 6) return;

    for(int i = n; i >= 2; i--) {
        if(i != 2 and i != n - 4) cout<<i<<" 2\n";
        else cout<<i<<" 1\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) solve();

    return 0;
}