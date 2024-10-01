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
    int x; cin>>x;
    int n = x / 1000, mod = x % 1000;
    ll fact1[999]; // 1 -> 0, 3 -> 1, 5 -> 2
    ll fact2[999]; // 0 -> 0, 2 -> 1, 4 -> 2
    fact1[0] = fact2[0] = 1;
    repx(i, 1, 999) {
        fact1[i] = (fact1[i-1] * (2 * i + 1)) % mod;
        fact2[i] = (fact2[i-1] * 2 * i) % mod;
        // cout<<i<<' '<<2 * i + 1<<' '<<fact1[i]<<'\n';
    }
    // cout<<n<<' '<<mod<<'\n';
    if(n % 2 == 0) cout<<fact2[n / 2]<<'\n';
    else cout<<fact1[n / 2]<<'\n';


    return 0;
}