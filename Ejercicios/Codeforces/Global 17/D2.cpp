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
    ll n; cin>>n;
    map<ll, ll> mapa;
    vi A(n); 
    ll ans = 0;
    rep(i, n) {
        cin>>A[i];
        if(!mapa.count(A[i])) mapa[A[i]] = 0;
        mapa[A[i]]++;
    }

    



    return 0;
}