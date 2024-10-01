#pragma GCC optimize("Ofast")
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int na, nb, k, m; cin>>na>>nb>>k>>m;
    vi A(na); rep(i, na) cin>>A[i];
    vi B(nb); rep(i, nb) cin>>B[i];
    if(A[k - 1] < B[nb - m]) cout<<"YES\n";
    else cout<<"NO\n";





    return 0;
}