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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

ll INF = 1e17;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n) {
        vi A(n); rep(i, n) cin>>A[i];
        sort(A.begin(), A.end());
        ll niv = 2;
        set<ii> S;
        rep(i, n) S.insert({A[i], 1e17});
        ll curr = 2, max = 2;
        ll nivel = 51;
        while(!S.empty()) {
            if(!(*S.begin()).ff != nivel) mx = max(mx, curr), curr = 2, niv = (*S.begin()).ff;
            
        }

    }





    return 0;
}