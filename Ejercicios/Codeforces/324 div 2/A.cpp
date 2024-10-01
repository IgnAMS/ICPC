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
    int n, t; cin>>n>>t;
    if(t != 10) {
        cout<<t; rep(i, n - 1) cout<<0; cout<<'\n';
    }
    else {
        if(n == 1) cout<<"-1"<<'\n';
        else { cout<<10; rep(i, n - 2) cout<<0; cout<<'\n'; }
    }




    return 0;
}