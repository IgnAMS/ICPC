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
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


void solve(vector<vector<bool>>& X, ll k){
    vector<vector<bool>> A, B;
    ll maxd = 0;
    rep(i, 31) if(k & (1<<i)) maxd = i;
    

}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, k; cin>>n>>k;
    vi A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());
    vi M(n, 0);
    rep(i, n){
        rep(j, 31) if(A[i] & (1LL<<j)) M[i] = j;
    }
    int i = 0;
    while(i < n and A[i] < k) i++;
    while(i + 1 < n and M[i] == M[i+1]){
        if()
    }





    return 0;
}