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

const int mxN = 2e6 + 5;
ll V[mxN];
ll A[mxN];
int n;


bool pos = 0;
void backtrack(int i) {
    if(i == 2 * n) {
        rep(i, 2 * n) cout<<A[i]<<' '; cout<<endl;
        pos = 1;
        return;
    }

    if(A[i]) backtrack(i + 1);
    repx(j, 1, n + 1) if(!V[j]) {
        if(i + j < 2 * n and !A[i + j]) {
            A[i + j] = j;
            A[i] = j;
            V[j] = 1;
            backtrack(i + 1);
            if(pos) return;
            V[j] = 0;
            A[i + j] = 0;
            A[i] = 0;
        }
    }
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    repx(i, 1, 20) {
        n = i;
        pos = 0;
        backtrack(0);
    }





    return 0;
}