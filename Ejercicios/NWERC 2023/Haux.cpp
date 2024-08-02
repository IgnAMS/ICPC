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
// g++ -O2 F.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cout<<pow(2, 38)<<' '<<pow(5, 21)<<' '<<pow(3, 35)<<'\n';
    // 50 / 3 = 48 = 10 + 6 = 3^17 * 2 = 3^15 * 4 * 4
    cout<<3 * 3* 2<<' '<<3 * 4 * 4<<'\n';



    return 0;
}