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
// g++ -O2 D.cpp && time ./a.out < input.txt > output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll k, x; cin>>k>>x;
        ll l = 1, r = 2 * k - 1;
        while(l < r){
            ll m = (l + r) / 2;
            ll acc;
            if(m > k) acc = k * (k + 1) / 2 + (k - 1) * k / 2 - (2 * k - m) * (2 * k - m - 1) / 2; 
            else acc = m * (m + 1) / 2;
            if(acc >= x) r = m;
            else l = m + 1; 
        }
        cout<<(l + r) / 2<<'\n';

    }

    return 0;
}