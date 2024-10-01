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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll maxi = 0, aux = n - 1;
        while(aux) maxi++, aux /= 2;
        // cout<<(1 << maxi)<<'\n';
        for(int i = n - 1; i >= (1 << (maxi - 1)); i--) cout<<i<<' '; 
        rep(i, (1 << (maxi - 1))) cout<<i<<' ';
        cout<<'\n';
    }



    return 0;
}