#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
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
// g++ -O2 DistinctValuesSubarrays.cpp && time ./a.out <input.txt> output.txt

const int INF = 1e9+1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll A[n]; 
    map<int, int> last;
    int left = 0;
    ll ans = 0;
    rep(i, n) {
        cin>>A[i];
        if(last.count(A[i])) left = max(left, last[A[i]]);
        last[A[i]] = i+1;
        ans += i+1 - left;
    }
    cout<<ans<<"\n";

    return 0;
}