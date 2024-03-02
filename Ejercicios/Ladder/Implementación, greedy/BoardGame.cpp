#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
     
     
// Given lines mantains a convex space to minimum queries, crescent slopes
// struct CHT {
//     vl A, B;
//     
//     db cross(int i, int j, int k) { 
//         return 1.d * (A[j] - A[i]) * (B[k] - B[i]) - 1.d * (A[k] - A[i]) * (B[j] - B[i]);
//     }
//  
//     void add(ll a, ll b) {
//         A.push_back(a);
//         B.push_back(b);
//  
//         while(A.size() > 2 and cross(A.size() - 3, A.size() - 2, A.size() - 1) <= 0) {
//             A.erase(A.end() - 2);
// 	        B.erase(B.end() - 2);
// 	    }
//     }
//      
//     ll query(ll x) {
//         if(A.empty()) return (long long)1e18;
//         int l = 0, r = A.size() - 1;
//  
//         while (l < r) {
//             int mid = l + (r - l)/2;
// 		    ll f1 = A[mid] * x + B[mid];
// 		    ll f2 = A[mid + 1] * x + B[mid + 1];
//  
// 			if(f1 > f2) l = mid + 1;
// 			else r = mid;
//         }
//  
//         return A[l] * x + B[l];
//       }
// };

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
	}
};
     
     
// n son los tokens y m son los jugadores
int n, m;
const int MxN = 1e5+7; 
int Ans[MxN];
pll Points[MxN], Lineas[MxN];
 
// Log jugadores * (jugadores + puntos) * log(jugadores)
 
// Las queries son los puntos a chequear
void pbs(int l, int r, vl& points) { 
    if(l > r or points.empty()) return;
 
    int mid = (l + r) / 2;
    CHT convexuhll;
    vector<pll> Copia;
    for(int i = l; i <= mid; i++) Copia.pb({Lineas[i].ff, Lineas[i].ss});
    sort(Copia.begin(), Copia.end());
    for(int i = 0; i < Copia.size(); i++) {
        convexuhll.add(-Copia[i].ff, -Copia[i].ss);
    }
 
    vl left_points, right_points;
    // cerr<<l<<' '<<mid<<' '<<r<<'\n';
    for(int i : points) {
        // cout<<"("<<Points[i].ff<<", "<<Points[i].ss<<"): "<<-convexuhll.eval(Points[i].ff)<<'\n';
        if(Points[i].ss < -convexuhll.eval(Points[i].ff)) {
            // cout<<"Con los pimeros "<<l<<' '<<mid<<" es posible resolver el punto "<<i<<'\n';
            Ans[i] = min(Ans[i], mid);
            left_points.pb(i);
        }
        else right_points.pb(i);
    }
    
    pbs(l, mid - 1, left_points);
    pbs(mid + 1, r, right_points);
}

 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>Points[i].ff>>Points[i].ss;
    cin>>m;
    rep(i, m) cin>>Lineas[i].ff>>Lineas[i].ss;
    
 
    vl points; 
    rep(i, n) points.pb(i);
    rep(i, n) Ans[i] = 1e8;

    pbs(0, m - 1, points);
    
    vector<vl> res(m, vl());
 
    rep(i, n) {
        if(Ans[i] != 1e8) res[Ans[i]].pb(i); 
    }
    
    rep(i, m) {
        cout<<res[i].size();
        for(auto u: res[i]) cout<<' '<<u + 1; cout<<'\n';
    }
 
 
    return 0;
}