#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include <algorithm>
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
// g++ -std=c++17 MissingCoinSum.cpp -o a && ./a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 FerrisWheel.cpp && time ./a.out <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, x; cin>>n>>x;
    ll A[n]; rep(i, n) cin>>A[i];
    sort(A, A+n);
    int i = 0, j = n - 1;
    ll ans = n;
    while(i < j) {
        if(A[i] + A[j] <= x) {
            ans--;
            i++, j--;
        }
        else {
            j--;
        }
    }
    cout<<ans<<"\n";


    
    return 0;
}