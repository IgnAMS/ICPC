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

vi primes;
void Sieve(int n){
	bool prime[n+1];
	memset(prime, 1, sizeof prime);
	for(int p = 2; p * p <= n; p++){
		if(prime[p]){
			for(int i = p * p; i<=n; i+=p){
				prime[i] = 0;
			}
		}
	}
	repx(i, 2, n+1) if(prime[i]) primes.push_back(i); 
}

struct FT{
    vector<int> t;
    FT(int N) { t.resize(N + 1, 0); }
    int query(int i)
    {
        int ans = 0;
        for (; i; i -= i & (-i)) {
			ans += t[i];
		}
		return ans;
    }
    int query(int i, int j) { return query(j) - query(i - 1); }
    void update(int i, int v)
    {
        int s = query(i, i); // Sets
		for (; i < t.size(); i += i & (-i)) t[i] += v;
    }
    void update(int i, int j, int v) { update(i, v); update(j + 1, -v); }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    Sieve(100001);
	int maxi[100001]; memset(maxi, -1, sizeof maxi);
	repx(i, 2, 100001){
		for(auto j: primes){
			if(j > sqrt(i) + 1) break; 
			if(i % j == 0) maxi[i] = max({maxi[j], maxi[i], maxi[i/j]});
		}
		if(maxi[i] == -1) maxi[i] = i;
	}
	
	map<int, int> mapa;
	rep(i, primes.size()) mapa[primes[i]] = i + 1;

	int q; cin>>q;
	vector<vector<int>> Q(q, {0, 0, 0});
	rep(i, q){
		int n, k; cin>>n>>k; Q[i] = {n, k, i};
	}
	sort(Q.begin(), Q.end());
	int j = 0;
	vi ans(q); 
	FT fen(primes.size());
	repx(i, 2, 100001){
		fen.update(mapa[maxi[i]], 1); 
		while(j < q and Q[j][0] == i){
			int p = *lower_bound(primes.begin(), primes.end(), Q[j][1]);
			if(p != Q[j][1]) p = *prev(lower_bound(primes.begin(), primes.end(), Q[j][1]));
			ans[Q[j][2]] = fen.query(1, mapa[p]);
			j++;
		}
	}
	rep(i, q) cout<<ans[i]<<'\n';


    return 0;
}