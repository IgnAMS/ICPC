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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, x; cin>>n>>x;
        if(n % x != 0) {
            cout<<"-1\n";
            continue;
        }
        vi A(n + 1); repx(i, 1, n + 1) A[i] = i;
        A[1] = x;
        A[n] = 1;
        repx(i, x + 1, n) {
            if(i % x == 0 and n % i == 0) {
                A[x] = i;
                x = i;
            }
        }
        if(x != n) A[x] = n;
        repx(i, 1, n + 1) cout<<A[i]<<' '; cout<<'\n';
        
    }


    return 0;
}