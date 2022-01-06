#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi; 
    
    vi Criba(int n){
    vector<bool> isPrime(n+1, true);
    vi lista;

    for(int k = 2; k*k <= n; k++){
        if (isPrime[k]){
            for(int j = k*k; j <= n; j += k){
                isPrime[j] = false;
            }
        }
    }

    for(int a=2; a<=n;a++){
        if (isPrime[a]){
            lista.emplace_back(a);
        }
    }

    return lista;
}