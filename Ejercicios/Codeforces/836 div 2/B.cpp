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
        if(n == 2) {
            cout<<3<<' '<<1<<'\n';
        }
        else if(n % 2) {
            rep(i, n) cout<<n<<' '; cout<<'\n';
        }
        else {
            rep(i, n - 2) cout<<2<<' ';
            cout<<1<<' '<<3<<'\n';
        }
    }





    return 0;
}