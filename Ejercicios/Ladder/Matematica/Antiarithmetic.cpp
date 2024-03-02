#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

void pos(vl& P, int n) {
    rep(i, n) for(int c = 1; c <= min(i, n - i - 1); c++) {
        if(P[i - c] <= P[i] and P[i] <= P[i + c]) {
            cout<<"no\n";
            // cout<<i - c<<' '<<i<<' '<<i + c<<'\n';
            return;
        }
        if(P[i - c] >= P[i] and P[i] >= P[i + c]) {
            cout<<"no\n";
            return;
        }
    }
    cout<<"yes\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; 
    char t;
    while(cin>>n>>t and n) {
        vl A(n); rep(i, n) cin>>A[i];
        vl P(n); rep(i, n) P[A[i]] = i;
        pos(P, n);
    }

    return 0;
}