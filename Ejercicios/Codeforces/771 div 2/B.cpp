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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];
        ll mximp = 0;
        ll mxpar = 0;
        bool oc = 1;
        rep(i, n) {
            if(A[i] % 2 == 0) {
                mxpar = max(A[i], mxpar);
                if(A[i] < mxpar) oc = 0;
            }
            else {
                mximp = max(A[i], mximp);
                if(A[i] < mximp) oc = 0;
            }
        }

        if(oc) cout<<"Yes\n";
        else cout<<"No\n";
        // 10 8
    }

    return 0;
}