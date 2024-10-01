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
    while(t--) {
        int n, k; cin>>n>>k;
        if(k < n - 1) {
            cout<<k<<' '<<n - 1<<'\n';
            repx(i, 1, n / 2) {
                if(i == k) cout<<0<<' '<<n - i - 1<<'\n';
                else if(n - i - 1 == k) cout<<i<<' '<<0<<'\n';
                else cout<<i<<' '<<n - i - 1<<'\n';
            }
        }
        else if(n != 4){
            cout<<n - 1<<' '<<n - 2<<'\n';
            cout<<n - 3<<' '<<1<<'\n';
            repx(i, 1, n - 3 - n / 2 + 1) {
                cout<<n / 2 + i - 1<<' '<<n / 2 - i<<'\n';
            }
            cout<<2<<' '<<0<<'\n';
        }
        else {
            cout<<"-1\n";
        }
        
    } 





    return 0;
}