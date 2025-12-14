#pragma GCC optimize("Ofast")
#include<iostream>
#include<vector>
#include<map>
#include<set>
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


vl X;
vector<vl> Ans[100];
void backtrack(int i, int n, int k, int suma) {
    Ans[i].pb(X);
    if(i == n) return;
    repx(j, 1, k+1) if((suma + j) % (i+1) == 0) {
        X.pb(j);
        backtrack(i+1, n, k, suma+j);
        X.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 12, k = 6;
    backtrack(0, n, k, 0);
    rep(i, n+1) {
        cout<<"Ans["<<i<<"]: "<<Ans[i].size()<<"\n";
        for(auto vec: Ans[i]) {
            cout<<"[";
            rep(j, vec.size()) {
                cout<<vec[j]<<(j == vec.size() - 1? "": ", ");
            }
            cout<<"]\n";

        }
        cout<<"\n";
    }
    // k = 1 -> el limite es 1, se alcanza en N=1 
    // k = 2 -> el limite es 2, se alcanza en N=1
    // k = 3 -> el limite es 5, se alcanza en N=2
    // k = 4 -> el limite es 10, se alcanza en N=3
    // k = 5 -> el limite es 23, se alcanza en N=4
    // k = 6 -> el limite es 48, se alcanza en N=5
    // k = 7 -> el limite es 115, se alcanza con N=6
    // k = 8 -> el limite es 240, se alcanza con N=7
    // k = 9 -> el limite es 565, se alcanza con N=8
    // k=10 -> el limite es 565, se alcanza con N=
    

    // Para cada k el limite se alcanza en k+1

    return 0;
}