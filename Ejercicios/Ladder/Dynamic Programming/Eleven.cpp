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


int n;
ll DP[101][51][51][12];

int dp(int i, int even, int odd, int mul) {
    if(i == n and mul == 0) return 1;
    if(i == n and mul != 0) return 0;


}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);






    return 0;
}