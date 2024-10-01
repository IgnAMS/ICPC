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
        int n, k; cin>>n>>k;
        vector<vector<char>> mat(n, vector<char>(n, '.'));
        if(k <= (n+1)/2){
            rep(i, k) mat[2*i][2*i] = 'R';
            rep(i, n) { rep(j, n) cout<<mat[i][j]; cout<<'\n'; }
        }
        else cout<<"-1\n";
    }




    return 0;
}