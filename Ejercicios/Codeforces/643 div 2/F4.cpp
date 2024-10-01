#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second
 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    vector<ll> primes; primes.push_back(2);
    repx(j, 1, 100000000){
        bool oc = 1;
        ll aux = 2 * j + 1;
        repx(i, 2, sqrt(aux) + 1) if(aux % i == 0) oc = 0;
        if(oc) primes.push_back(aux);
        if(primes.size() == 44) break;
    }
    // tiempo logaritmico para 
    map<ll, vector<ll>> mult;
    vector<ll> Q;
    rep(i, 22){
        ll aux1 = 1, aux2 = 1; 
        mult[primes[2*i]] = vector<ll>();
        mult[primes[2*i + 1]] = vector<ll>();
        while(0 <= aux1 * primes[2*i] and aux1 * primes[2*i] <= 1000000000){
            aux1 *= primes[2*i];
            mult[primes[2*i]].push_back(aux1);
        }
        while(0 <= aux2 * primes[2*i + 1] and aux2 * primes[2*i + 1] <= 1000000000){
            aux2 *= primes[2*i + 1];
            mult[primes[2*i + 1]].push_back(aux2);
        }
        Q.push_back(aux1 * aux2);
    }
 
 
    int t; cin>>t;
    while(t--){
        vector<ll> gcds;
        ll num = 1;
        rep(i, 22) {
            cout<<"? "<<Q[i]<<endl;
            cerr<<"que ondi xd"<<endl;
            ll h; cin>>h;
            if(h != 1) gcds.push_back(h);
            num *= h;
        }
        // calculo la cantidad maxima de divisores que tiene
        // luego, le tiro el maximo que podria tener dado que tiene esos datos
        vector<int> numeros;
        rep(i, 44) { // O(44 * 20 * log(10^9)) = O(26000), que es chico
            bool oc = 1;
            rep(j, mult[primes[i]].size()) { // gcd se demora logaritmo del mas chico
                if(num % mult[primes[i]][j] != 0) {
                    // cout<<num<<' '<<mult[primes[i]][j]<<endl;
                    if(j) numeros.push_back(j + 1); // si j es 0 entonces no hay numeros
                    oc = 0;
                    break;
                }
            }
            if(oc) numeros.push_back(mult[primes[i]].size()); // todos dividen al numero 
        }
        // cout<<num<<endl;
        // rep(i, numeros.size()) cout<<numeros[i]<<' '; cout<<endl;
        ll ans = 1;
        rep(i, numeros.size()) if(numeros[i] != 0) {
            ans *= numeros[i];
            cout<<numeros[i]<<endl;
        }
        ll x=0; 
        ll h = 200;
        ans *= 2;
        cout<<"! "<<ans<<endl;
    }
 
    return 0;
}