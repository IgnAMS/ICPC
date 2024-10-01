#include<bits/stdc++.h>
#include <chrono>
#include <ctime>    
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<ll> primos;
void SieveOfEratosthenes(int n) { 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
    
    for (int p=2; p*p<=n; p++){ 
        if (prime[p] == true) { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    }   
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) {
           primos.push_back(p);
       }
          
} 


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;

    SieveOfEratosthenes(1000000);
    while(t--){
        ll d; cin>>d;
        ll a=1;
        ll i=0;
        while(primos[i]-a<d) i++;
        ll ans=primos[i];
        a=ans;
        while(primos[i]-a<d) i++;
        ans*=primos[i];
        cout<<ans<<"\n";
    }

    return 0;
}