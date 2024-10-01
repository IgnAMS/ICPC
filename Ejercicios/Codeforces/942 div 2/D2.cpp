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
    cout<<"\t";
    repx(i, 1, 100) cout<<i<<'\t';
    cout<<'\n';
    repx(a, 1, 100) {
        cout<<a<<'\t';
        repx(b, 1, 100) {
            if((b * __gcd(a, b)) % (a + b) == 0) cout<<"x\t";
            else cout<<".\t";
        }
        cout<<'\n';
    }


    return 0;
}