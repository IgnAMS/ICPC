#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
	while(t--) {
		int n; cin>>n;
		ll A[n]; 
		ll imp = 0, par = 0;
		rep(i, n) {
			cin>>A[i];
			if(A[i] % 2) imp++;
			else par++;
		}
		// No necesito cambiar nada 
		if(imp % 2 == 1) cout<<"YES\n";
		// Todos son impares y tengo una cantidad impar
		else if(imp == n and n % 2 == 0) cout<<"NO\n";
		// Todos son pares
		else if(par == n) cout<<"NO\n";
		// Tengo una cantidad par de impares y tengo al menos un impar
		else cout<<"YES\n";

	}


    return 0;
}