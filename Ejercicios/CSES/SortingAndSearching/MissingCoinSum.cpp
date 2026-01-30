#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<map>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    A.pb(0);
    sort(A.begin(), A.end());
    ll curr = 0;
    rep(i, n) {
        // cout<<curr<<" "<<A[i + 1]<<"\n";
        if(curr < A[i + 1] - 1) {
            cout<<curr + 1<<"\n";
            return 0;
        }
        curr += A[i+1];
    }
    cout<<curr + 1<<"\n";
    

    return 0;
}