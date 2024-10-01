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
        int n, a, b; cin>>n>>a>>b;
        if(n - b + (a<=b) <= n/2 and a - 1 + (a<=b) <=n/2){
            rep(i, n/2) if(n - i != b) cout<<n - i<<' ';
            if(a<=b) cout<<a<<' '; 

            rep(i, n/2) if(i + 1 != a) cout<<i + 1<<' ';
            if(a<=b) cout<<b;
            cout<<'\n';
        } 
        else cout<<"-1\n";

    }


    return 0;
}