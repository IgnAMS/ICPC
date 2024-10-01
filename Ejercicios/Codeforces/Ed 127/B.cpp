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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        bool pos = 1;
        vi A(n); rep(i, n) cin>>A[i];
        rep(i, n) if(A[i] - A[0] >= i + 3) {
            pos = 0;
        }

        rep(i, n) if(A[i] - A[0] <= i - 3) {
            pos = 0;
        }

        cout<<(pos? "YES\n": "NO\n");
    }


    return 0;
}