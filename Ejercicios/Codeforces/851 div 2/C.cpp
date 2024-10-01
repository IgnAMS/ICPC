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
        if(n % 2 == 0) {
            cout<<"No\n";
            continue;
        }

        vector<pll> A(n);
        rep(i, n) A[i] = {i + 1, 2 * n - i}; 
        // rep(i, n) cout<<A[i].ff<<' '<<A[i].ss<<'\n'; cout<<'\n';
        int aux = n / 2; 
        for(int i = 0; i <= n / 4; i++) {
            A[i].ss -= aux;
            A[i + aux].ss += aux;
            aux -= 2;
        }
        aux = n / 2 - 1;
        for(int i = n / 2 + 1; i < n / 2 + 1 + n / 4; i++) {
            A[i].ss -= aux;
            A[i + aux].ss += aux;
            aux -= 2; 
        }
        cout<<"Yes\n";
        for(int i = 0; i < n; i++) cout<<A[i].ff<<' '<<A[i].ss<<'\n';


    }





    return 0;
}