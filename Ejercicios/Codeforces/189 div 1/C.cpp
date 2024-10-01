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

const ll mxN = 100005;
ll DP[mxN];
ll A[mxN], B[mxN];
int n;

ll dp(ll i) {
    if(i == n - 1) return 0;
    if(DP[i] != -1) return DP[i];

    DP[i] = 1e17;
    repx(j, i + 1, n) DP[i] = min(DP[i], dp(j) + B[i] * A[j]);
    // cout<<"i: "<<i<<", DP: "<<DP[i]<<'\n';
    return DP[i];
}

typedef ll tc;
struct Line{tc m,h;};
struct CHT { // for minimum (for maximum just change the sign of lines)
	vector<Line> c;
	int pos=0;
	tc in(Line a, Line b){
		tc x=b.h-a.h,y=a.m-b.m;
		return x/y+(x%y?!((x>0)^(y>0)):0); // ==ceil(x/y)
	}
	void add(tc m, tc h){ // m's should be non increasing
		Line l=(Line){m,h};
		if(c.size()&&m==c.back().m){
			l.h=min(h,c.back().h);c.pop_back();if(pos)pos--;
		}
		while(c.size()>1&&in(c.back(),l)<=in(c[c.size()-2],c.back())){
			c.pop_back();if(pos)pos--;
		}
		c.pb(l);
	}
	inline bool fbin(tc x, int m){return in(c[m],c[m+1])>x;}
	tc eval(tc x){
		// O(log n) query:
		int s=0,e=c.size();
		while(e-s>1){int m=(s+e)/2;
			if(fbin(x,m-1))e=m;
			else s=m;
		}
		return c[s].m*x+c[s].h;
		// O(1) query (for ordered x's):
		while(pos>0&&fbin(x,pos-1))pos--;
		while(pos<c.size()-1&&!fbin(x,pos))pos++;
		return c[pos].m*x+c[pos].h;
	}
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>A[i];
    rep(i, n) cin>>B[i];
    rep(i, n) DP[i] = -1;

    
    CHT ch;
    ch.add(-A[n - 1], 0);
    // DP[i] = max_j A[j] * B[i] + DP[j]
    // DP[i] = - (min_j (-A[j]) * B[i] + (-DP[j]))
    for(int i = n - 2; i >= 1; i--) {
        ll curr = -ch.eval(B[i]); 
        ch.add(-A[i], -curr);
    }
    cout<<-ch.eval(B[0])<<'\n';

    return 0;
}