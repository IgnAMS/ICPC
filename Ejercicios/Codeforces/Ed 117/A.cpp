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
        int a, b; cin>>a>>b;
        ii ans = {-1, -1};
        rep(i, 101) rep(j, 101) {
            if((i + j) * 2 == a + b and (abs(a-i) + abs(b-j)) * 2 == a+b) ans = {i, j};
        }
        cout<<ans.ff<<' '<<ans.ss<<'\n';


    }





    return 0;
}