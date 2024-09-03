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
        vl X(n);
        rep(i, n) cin>>X[i];

        sort(X.begin(), X.end());
        int mex = X.size();
        rep(i, (int)X.size() - 1) {
            if(X[i] + 1 < X[i + 1]) {
                mex = X[i] + 1;
                break;
            }
            if(X[i] == X[i + 1]) mex--;
        }
        if(X[0] != 0) mex = 0;
        cout<<mex<<'\n';
    }

    

    return 0;
}



