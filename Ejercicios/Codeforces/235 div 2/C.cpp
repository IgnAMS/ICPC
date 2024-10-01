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


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t = 1; 
    
    while(t--) {
        int n, m; cin>>n>>m;
        if(m > 2 * n + 2 or m < n - 1) { 
            cout<<"-1\n";
            continue;
        }

        bool one = (m > 2 * n); 
        int cont = 0;
        while((n > 0 or m > 0) and cont++ < 2000000) {
            cout<<one;
            if(one) m--;
            else n--;
            one = (m > 2 * n? 1: !one);
        }
        cout<<'\n';
    }
    





    return 0;
}