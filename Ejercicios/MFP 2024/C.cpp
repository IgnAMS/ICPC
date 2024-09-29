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
    int a, b; cin>>a>>b;
    repx(i, 1, a + 1) if(a % i == 0) {
        ll vueltasa = a / i;
        ll vueltasb = b / i;
        if(vueltasa == vueltasb + 1) {
            cout<<i<<'\n';
            return 0;
        }
    }

    return 0;
}