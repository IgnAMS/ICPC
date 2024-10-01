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
        int n; cin>>n;
        int n2 = n;
        vi A(n);
        while(n != 0) {
            if(n == 1) A[0] = 1, n = 0;
            else {
                A[n - 2] = n, A[n - 1] = n - 1;
                n -= 2;
            }
        } 
        rep(i, n2) cout<<A[i]<<' '; cout<<'\n';

    }





    return 0;
}