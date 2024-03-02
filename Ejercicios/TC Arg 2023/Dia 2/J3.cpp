#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 55;

int n, a = 0, b = 0, x[mxN];

int main(){
    cin >> n;
    rep(i, n){
        cin >> x[i];
    }    
    for(int i = n-1; i>=0; --i){
        if(a<b){
            a += x[i];
        }else{
            b += x[i];
        }
    }
    if(a > b) swap(a, b);
    cout << a << " " << b << '\n';
}


// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 G.cpp && time ./a.out <input.txt> output.txt
