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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vl A(n); rep(i, n) { cin>>A[i]; A[i]--; }
        vl Acc(n + 1, 0); 
        rep(i, n) Acc[i + 1] = Acc[i] + A[i];
        bool oc = 0;
        int mn = -1;
        repx(i, 1, n) if(Acc[i] == Acc[n] - Acc[i] and !oc) oc = 1, mn = i;
        cout<<mn<<'\n'; 

    }



    return 0;
}