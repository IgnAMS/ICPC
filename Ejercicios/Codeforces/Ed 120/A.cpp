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
        int a, b, c; cin>>a>>b>>c;
        if((a == b and c % 2 == 0) or (a == c and b % 2 == 0) or (c == b and a % 2 == 0)){
            cout<<"YES\n";
        }
        else if((a + b == c) or (a + c == b) or (c + b == a)){
            cout<<"YES\n";
        }
        else cout<<"NO\n";


    }



    return 0;
}