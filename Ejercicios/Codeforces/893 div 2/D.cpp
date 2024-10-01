#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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


typedef ll tc;
struct Line{tc m,h;};
struct CHT { // for minimum (for maximum just change the sign of lines)
	vector<Line> c;
	int pos=0;
	tc in(Line a, Line b) {
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
		// while(pos>0&&fbin(x,pos-1))pos--;
		// while(pos<c.size()-1&&!fbin(x,pos))pos++;
		// return c[pos].m*x+c[pos].h;
	}
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t-- ) {
        ll n, k; cin>>n>>k;
        string s; cin>>s;
        vl L1(n + 1, 0), L0(n + 1, 0);
        ll unos = 0, ceros = 0;

        rep(i, n) {
            if(s[i] == '0') unos = 0, ceros++;
            else ceros = 0, unos++;
            L1[i + 1] = max(L1[i], unos);
            L0[i + 1] = max(L0[i], ceros);
        }
        vl R1(n + 1, 0), R0(n + 1, 0);
        unos = 0, ceros = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') unos = 0, ceros++;
            else ceros = 0, unos++;
            R1[i] = max(R1[i + 1], unos);
            R0[i] = max(R0[i + 1], ceros);
        }
        
        vector<pll> E;
        rep(i, n) {
            ll cost0 = 0, cost1 = 0;
            repx(j, i, n) {
                if(s[j] == '1') cost0++;
                else cost1++;
                if(cost0 <= k) {
                    E.emplace_back(-max({L0[i], ll(j - i + 1), R0[j + 1]}), -max({L1[i], R1[j + 1]}));
                }
                if(cost1 <= k) {
                    E.emplace_back(-max({L0[i], R0[j + 1]}), -max({L1[i], ll(j - i + 1), R1[j + 1]}));
                }
            }
        }
        sort(E.begin(), E.end(), [&](const pll a, const pll b) {
            if(a.ff == b.ff) return a.ss > b.ss;
            return a.ff > b.ff;
        });

        CHT cht;
        for(auto u: E) { 
            cht.add(u.ff, u.ss);
        }
        repx(i, 1, n + 1) cout<<-cht.eval(i)<<' '; cout<<'\n';
    }

    return 0;
}