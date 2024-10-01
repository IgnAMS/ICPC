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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // Debo sacar elementos consecutivos de largo k
    // Largo final = n % k
    // x = (n % k) / 2
    
    // Como metrica quiero quedarme con los elementos mas grandes :)
    // DP[i][j][x] = min_{0 <= y < x, i <= l <= j - y * k}(merge(DP[i][l][y], DP[l+k][j][x-y-1])) 
    // merge(DP[i][l][y], DP[l+k][j][x-y-1]) = sum F_l[i] + F_r[i]

    // DP[i][x] = min{}






    return 0;
}