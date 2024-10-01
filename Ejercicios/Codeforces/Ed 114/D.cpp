#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<set<ii>> A(n, set<ii>());
    rep(i, n){
        int c; cin>>c;
        rep(j, c) { int h; cin>>h; A[i].insert(ii(h, j)); }
    }
    int m; cin>>m;
    rep(_, m){
        vector<set<int>> h;
        
    }





    return 0;
}