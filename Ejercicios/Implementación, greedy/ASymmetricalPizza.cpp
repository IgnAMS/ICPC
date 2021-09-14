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
    double R; cin>>R;
    ll a = R * 100 + 1e-6;
    cout<<(((a * 36000) / __gcd(a, ll(36000))) / a)<<'\n';


    return 0;
}