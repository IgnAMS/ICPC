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
    int n; cin>>n;
    rep(i, n + 1) {
        rep(j, n - i) cout<<"  ";
        rep(j, (i + 1)) cout<<j<<" \n"[i == 0];
        rep(j, i) cout<<i - j - 1<<" \n"[j == i - 1];  
    }
    rep(i, n) {
        rep(j, i + 1) cout<<"  ";
        rep(j, n - i) cout<<j<<" \n"[i == n - 1];
        rep(j, n - i - 1) cout<<n - i - 2 - j<<" \n"[j == n - i - 2];
    }





    return 0;
}