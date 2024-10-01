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
    vi primes = {2};
    repx(i, 2, 2 * 1e5) {
        bool oc = 1;
        repx(j, 2, sqrt(i) + 1){
            if(i % j == 0) { oc = 0; break; }
        }
        if(oc) primes.push_back(i);
    }

    ll n; cin>>n;
    if(n % 2 == 0){
        cout<<n / 2 <<'\n';
    }
    else{
        ll aux = n;
        rep(i, primes.size()) if(n % primes[i] == 0) { 
            aux = primes[i]; 
            break;
        }
        if(aux == n) cout<<1<<'\n';
        else cout<<1 + (n - aux) / 2<<'\n';
    }
    





    return 0;
}