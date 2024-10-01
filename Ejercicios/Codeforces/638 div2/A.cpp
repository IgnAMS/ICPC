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
    while(t--){
        int n; cin>>n;
        ll aux1 = 0, aux2 = 0;
        rep(i, n/2-1) aux1 += (1<<(i+1));
        aux1 += (1<<n);
        repx(i, n/2, n) aux2 += (1<<i);
        cout<<aux1- aux2<<'\n';

    }


    return 0;
}