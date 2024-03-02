#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

int main () {
    vector<int> v = {10,20,30,30,20,10,10,20};          // 10 20 30 30 20 10 10 20
    sort (v.begin(), v.end());                       // 10 10 10 20 20 20 30 30
    auto low = lower_bound (v.begin(), v.end(), 20); //          ^
    auto up  = upper_bound (v.begin(), v.end(), 20); //                    ^
    cout << "lower_bound at position " << (low - v.begin()) << '\n';
    cout << "upper_bound at position " << (up - v.begin()) << '\n';
    return 0;
}