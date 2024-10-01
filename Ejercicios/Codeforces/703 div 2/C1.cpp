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
// g++ -std=c++11 C1.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	ll l = 0, r = n - 1;
	while(l < r) {
		ll m = (l + r) / 2;
		cout<<"? "<<l + 1<<' '<<r + 1<<endl;
		ll x; cin>>x; x--;
		// cout<<"x: "<<x<<endl;
		// caso base
		if(r - l == 1) {
			if(x == l) l = r;
			else r = l;
			continue;
		}
		if(r - l == 2 and x == r) {
			r = m;
			continue;
		}

		// Pregunto por el segmento qeu tiene a x
		if(l <= x and x <= m) cout<<"? "<<l + 1<<' '<<m + 1<<endl;
		else cout<<"? "<<(m + 1) + 1<<' '<<r + 1<<endl;
		ll y; cin>>y; y--;


		// si son diferentes entonces uso el intervalo contrairo
		if(y != x) {
			if(l <= x and x <= m) l = m + 1;
			else if(m + 1 <= x and x <= r) r = m;
		}
		else {
			if(l <= x and x <= m) r = m;
			else if(m + 1 <= x and x <= r) l = m + 1;
		}
	}
	cout<<"! "<<l + 1<<'\n';

    return 0;
}