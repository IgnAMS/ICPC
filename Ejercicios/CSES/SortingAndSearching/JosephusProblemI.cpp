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
// g++ -O2 JosephusProblemI.cpp && time ./a.out <input.txt> output.txt

const int INF = 1e9+1;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<ll> A;
    rep(i, n) A.pb(i);
    while(A.size() > 1) {
        for(int i = 1; i < A.size(); i += 2) cout<<A[i] + 1<<" ";
        vl B;
        int last_even = (A.size() / 2) * 2;
        for(int i = last_even; i < A.size(); i += 2) {
            B.pb(A[i]);
        }
        for(int i = 0; i < last_even; i += 2) {
            B.pb(A[i]);
        }
        swap(A, B);
    }
    cout<<A[0] + 1<<"\n";

    return 0;
}