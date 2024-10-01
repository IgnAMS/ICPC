#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const db PI = acos(-1.0L);
const db EPS = 1e-12;

db ang(ll x, ll y) {
    db a = atan2(y, x);
    if (a < 0) a += 2. * PI;
    return a;
}

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
    int n; cin>>n;
    vector<vi> P(n, vi(3)); // y, xl, xr
    rep(i, n) cin>>P[i][1]>>P[i][2]>>P[i][0];
    sort(P.begin(), P.end());

    vector<pair<db, int>> Angles;
    rep(i, n) rep(j, i) {
        Angles.push_back({ang(P[j][1] - P[i][2], P[j][0] - P[i][0]), 1});
        Angles.push_back({ang(P[j][2] - P[i][1], P[j][0] - P[i][0]), 0});
    }
    sort(Angles.begin(), Angles.end());
    for(auto u: Angles) cout<<"("<<u.ff<<", "<<u.ss<<"), "; cout<<'\n';

     



    return 0;
}