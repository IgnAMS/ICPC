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
    // vector<ll> primes; primes.push_back(2);
    // repx(j, 1, 100000000){
    //     bool oc = 1;
    //     ll aux = 2 * j + 1;
    //     repx(i, 2, sqrt(aux) + 1) if(aux % i == 0) oc = 0;
    //     if(oc) primes.push_back(aux);
    //     if(primes.size() == 168) break;
    // }
    // 
    // cout<<"{";
    // rep(i, primes.size()) cout<<" "<<primes[i]<<",}"[i==primes.size()-1]; cout<<'\n';

    // primeros 168 primos, todos tienen a lo mas 3 potencias <= 10^9
    vector<ll> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47,
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137,
    139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227,
    229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313,
    317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419,
    421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509,
    521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617,
    619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727,
    733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829,
    839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947,
    953, 967, 971, 977, 983, 991, 997 }; 


    map<ll, vector<ll>> mult;
    vector<ll> Q;
    rep(i, primes.size() / 2){ // hasta 22 ta gucci
        ll aux1 = 1, aux2 = 1; 
        mult[primes[2*i]] = vector<ll>();
        mult[primes[2*i + 1]] = vector<ll>();
        int j;
        for(j = 0; aux1 * primes[2*i] <= 1000000000; aux1 *= primes[2*i], j++){
            mult[primes[2*i]].push_back(aux1 * primes[2*i]);
        }
        //cout<<primes[2*i]<<' '<<j<<endl;
        for(j = 0; aux2 * primes[2*i+1]<= 1000000000; aux2 *= primes[2*i + 1], j++){
            mult[primes[2*i + 1]].push_back(aux2 * primes[2*i + 1]);
        }
        //cout<<primes[2*i + 1]<<' '<<j<<endl;
        Q.push_back(aux1 * aux2);
    }
    int ind = 0; // indice en el que voy 
    vector<int> A;
    while(ind < 168) {
        ll mul = 1;
        while(ind < 168 and 0 <= mul * primes[ind] and 
                mul * primes[ind] < 1000000000000000000) {
            mul *= primes[ind++];
            cout<<"multiplico por "<<primes[ind-1]<<'\n';
        }
        cout<<mul<<'\n';
        A.push_back(mul);
    }
    cout<<A.size()<<endl;


    int t; cin>>t;
    while(t--){
        vector<ll> gcds;
        ll num = 1;
        map<int, int> pot;
        map<int, int> base; // esta es la base que usare para empezar
        
        rep(i, 22) {
            cout<<"? "<<Q[i]<<endl;
            ll h; cin>>h;
            if(h != 1) gcds.push_back(h);
            else{

            }
            num = num / __gcd(num, h) * h;
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
        rep(i, numeros.size()) if(numeros[i] != 0) ans *= numeros[i];
        
        ll x = 0; 
        ll h = 200;
        ans *= 2;
        cout<<"! "<<max(ans, ans / 2 + 7)<<endl;
    }

    return 0;
}