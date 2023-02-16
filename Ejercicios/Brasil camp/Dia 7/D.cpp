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
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


typedef ll tc;
struct Line{ tc m, h; };
struct CHT { // for minimum (for maximum just change the sign of lines)
	vector<Line> c;
    vi I;
	int pos=0;
	tc in(Line a, Line b){
		tc x=b.h-a.h,y=a.m-b.m;
		return x / y + (x % y? !((x>0)^(y>0)) : 0); // ==ceil(x/y)
	}
	void add(tc m, tc h, int id){ // m's should be non increasing
		Line l=(Line){m, h};
		if(c.size() and m == c.back().m){
			l.h = min(h, c.back().h);
            c.pop_back();
            I.pop_back();
            if(pos)pos--;
		}
		while(c.size() > 1 and in(c.back(),l) <= in(c[c.size()-2], c.back())){
			c.pop_back();
            I.pop_back();
            if(pos)pos--;
		}
		c.pb(l);
        I.pb(id);
	}
	inline bool fbin(tc x, int m) { return in(c[m], c[m + 1]) > x;}
	tc eval(tc x){
		// O(log n) query:
		int s=0,e=c.size();
		while(e - s > 1 ){
            int m=(s+e)/2;
			if(fbin(x,m-1))e=m;
			else s=m;
		}
		return c[s].m * x + c[s].h;
		// O(1) query (for ordered x's):
		while(pos>0&&fbin(x,pos-1))pos--;
		while(pos<c.size()-1&&!fbin(x,pos))pos++;
		return c[pos].m*x+c[pos].h;
	}
    int ind(tc x) {
        int s=0,e=c.size();
		while(e - s > 1 ){
            int m=(s+e)/2;
			if(fbin(x,m-1))e=m;
			else s=m;
		}
		return I[s];
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s, t; cin>>n>>m>>s>>t; s--, t--;
    vi H(n); rep(i, n) cin>>H[i];
    vector<vi> G(n, vi());
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    
    priority_queue<ii, vector<ii>, greater<ii>> pq; pq.push({0, s});
    vi DS(n, 1e17);
    DS[s] = 0;
    ll aux1 = 1e17;
    while(!pq.empty()) {
        auto x = pq.top(); pq.pop();
        ll u = x.ss, d = x.ff;
        if(DS[u] < d) continue;
        for(auto v: G[u]) if(DS[v] > DS[u] + (H[u] - H[v]) * (H[u] - H[v])) {
            DS[v] = DS[u] + (H[u] - H[v]) * (H[u] - H[v]);
            pq.push({DS[v], v});
            if(v == t) aux1 = min(aux1, DS[u]);
        }
    }

    
    pq.push({0, t});
    vi DT(n, 1e17);
    DT[t] = 0;
    ll aux2 = 1e17;
    while(!pq.empty()) {
        auto x = pq.top(); pq.pop();
        ll u = x.ss, d = x.ff;
        if(DT[u] < d) continue;
        for(auto v: G[u]) if(DT[v] > DT[u] + (H[u] - H[v]) * (H[u] - H[v])) {
            DT[v] = DT[u] + (H[u] - H[v]) * (H[u] - H[v]);
            pq.push({DT[v], v});
            if(v == s) aux2 = min(aux2, DT[u]);
        }
    }
    // cout<<aux1<<' '<<aux2<<'\n';
    // cout<<"DS:\n";
    // rep(i, n) cout<<DS[i]<<' '; cout<<'\n';
    // cout<<"DT:\n";
    // rep(i, n) cout<<DT[i]<<' '; cout<<'\n';
    // cout<<'\n';
    

    ll ans = 0;
    ll mini = 1e18;
    rep(u, n) if(u != s and u != t) {
        sort(G[u].begin(), G[u].end(), [&](int a, int b){
            return H[a] < H[b];
        });
        CHT cht;
        for(auto v: G[u]) {
            // cout<<v + 1<<' '<<H[v]<<'\n';
            cht.add(-2 * H[v], H[v] * H[v] + 2 * DT[v], v);
        }
        // for(auto it: cht.c) cout<<it.m<<' '<<it.h<<'\n';
        // cout<<"estoy en u: "<< u<<'\n';
        for(auto v: G[u]) {
            // cout<<"pruebo para v: "<<v<<"\n";
            // cout<<H[v] * H[v] + 2 * DS[v]<<' '<<cht.eval(H[v])<<'\n';
            // cout<<H[v] * H[v] + 2 * DS[v] + cht.eval(H[v])<<'\n';
            if(H[v] * H[v] + 2 * DS[v] + cht.eval(H[v]) < mini) {
                mini = H[v] * H[v] + 2 * DS[v] + cht.eval(H[v]);
                int w = cht.ind(H[v]);
                ans = abs(2 * H[u] - H[v] - H[w]);
                // cout<<"para el nodo "<<u + 1<<" me conviene usar los nodos "<<v + 1<<' '<<w + 1<<'\n';
                // cout<<db(mini) / 2.<<'\n';
            }
            // cout<<'\n';
        }

    }
    if(min(aux1, aux2) * 2 < mini) cout<<min(aux1, aux2)<<'\n';
    else cout<<setprecision(7)<<fixed<<db(mini) / 2.<<'\n';



    return 0;
}