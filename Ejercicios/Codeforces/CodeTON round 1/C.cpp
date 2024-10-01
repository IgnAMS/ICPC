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
        ll n; cin>>n;
        vi A(n); rep(i, n) cin>>A[i];

        bool uno = 0;
        rep(i, n) if(A[i] == 1) uno = 1;
        if(!uno or n == 1) {
            cout<<"YES\n";
            continue;
        }
        sort(A.begin(), A.end());
        vi D(n - 1); rep(i, n - 1) D[i] = A[i + 1] - A[i];
        bool pos = 1;
        rep(i, n - 1) if(D[i] == 1) pos = 0; 
        if(pos) cout<<"YES\n";
        else cout<<"NO\n";

    }


    return 0;
}