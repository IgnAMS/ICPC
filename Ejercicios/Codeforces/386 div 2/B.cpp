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
    string s; cin>>s;
    vector<char> ans(n, '.');
    int mid = (n-1)/2;
    bool sw = 0;
    rep(i, n){
        ans[mid] = s[i];
        if(n % 2 == 0) mid += (sw? -1: 1) * (i + 1);
        if(n % 2 == 1) mid += (sw? 1: -1) * (i + 1);
        sw = !sw;
    }
    rep(i, n) cout<<ans[i]; cout<<'\n';





    return 0;
}