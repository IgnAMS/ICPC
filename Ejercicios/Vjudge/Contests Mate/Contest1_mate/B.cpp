#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
set<ll> almostPrimes;

void Criba(int n){
    vector<bool> isPrime(n+1, true);

    for(int k = 2; k*k <= n; k++){
        if (isPrime[k]){
            for(int j = k*k; j <= n; j += k){
                isPrime[j] = false;
            }
        }
    }

    for(int a=2; a<=n;a++){
        if (isPrime[a]){
            almostPrimes.insert(ll(a)*ll(a));
        }
    }
    return;
}


int main(){
    //OJ;
    int t; cin>>t;
    ll n;
    Criba(1e6+1);
    for(int i=0;i<t;i++){
        cin>>n;
        if(almostPrimes.count(n)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}