#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

// crescent slopes
struct CHT {
    vi A, B;
 
    // Observation, this multiplication is really big
    db cross(int i, int j, int k) { 
        return 1.d * (A[j] - A[i]) * (B[k] - B[i]) - 1.d * (A[k] - A[i]) * (B[j] - B[i]);
    }
 
    void add(ll a, ll b) {
        A.push_back(a);
        B.push_back(b);
 
        while(A.size() > 2 and cross(A.size() - 3, A.size() - 2, A.size() - 1) <= 0) {
            A.erase(A.end() - 2);
	        B.erase(B.end() - 2);
	    }
    }
 
    ll query(ll x) {
        if(A.empty()) return (long long)1e18;
        int l = 0, r = A.size() - 1;

        while (l < r) {
            int mid = l + (r - l)/2;
		    ll f1 = A[mid] * x + B[mid];
		    ll f2 = A[mid + 1] * x + B[mid + 1];
 
			if(f1 > f2) l = mid + 1;
			else r = mid;
        }
 
        return A[l] * x + B[l];
      }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    vi A(n); rep(i, n) cin>>A[i];
    vi Acc(n + 1, 0); rep(i, n) Acc[i + 1] = Acc[i] + A[i];  
    ll aux = 0; rep(i, n) aux += A[i] * (i + 1);
    CHT hull;
    ll ans = 0;
    rep(i, n) {
        if(i) {
            ll tmp = Acc[i] - A[i] * i - hull.query(-A[i]);
            ans = max(ans, tmp);
        }
        hull.add(i, Acc[i]);
    }

    CHT hull2;
    for(ll i = n - 1; i >= 0; i--) {
        if(i != n - 1) {
            ll tmp = Acc[i + 1] - A[i] * i - hull2.query(A[i]);
            ans = max(ans, tmp);
        }
        hull2.add(-i, Acc[i + 1]);
    }

    cout<<ans + aux<<'\n';

    return 0;
}