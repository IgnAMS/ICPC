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
        ll x, y; cin>>x>>y;
        ll a, b; cin>>a>>b;
        if(x * y < 0) cout<<a * (abs(x) + abs(y))<<'\n';
        else{
            cout<<a * abs(x - y) + min(2 * a, b) * min(abs(x), abs(y))<<'\n';
        }

    }


    return 0;
}