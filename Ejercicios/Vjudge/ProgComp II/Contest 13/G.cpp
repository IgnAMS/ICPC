#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef pair<int,double> ii;
#define ff first
#define ss second

struct e{
    int u, v; double d;
    e(int u, int v, double d): u(u), v(v), d(d) {}
};

struct MST{
    vector<int> p;
    int n; 
    double d1,d2;
    int r;
    int states;
    MST(vector<e>& E, int s ,int a){
        r=a;
        n=E.size(); p.assign(n,-1); states=s;
        d1=0,d2=0;
        sort(E.begin(),E.end(),[&](const e& a, const e& b){
            return a.d<b.d;
        });
        rep(i,0,n) U(E[i].u,E[i].v,E[i].d);
    }

    void U(int u, int v, double d){
        int x=find(u), y=find(v);
        if(x==y) return;
        if(-p[y]>-p[x]) swap(x,y);
        if(d<=r) { d1 += d; states--; }
        else d2 += d;
        p[x]+=p[y];
        p[y]=x;
    }

    int find(int u){ return p[u]<0? u:p[u]=find(p[u]); }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    rep(cas,0,t){
        int n,r; cin>>n>>r;
        vector<ii> A(n);
        vector<e> E;
        rep(i,0,n) cin>>A[i].ff>>A[i].ss;
        rep(i,0,n){
            rep(j,i+1,n){
                ll d= (A[i].ff-A[j].ff)*(A[i].ff-A[j].ff);
                d+= (A[i].ss-A[j].ss)*(A[i].ss-A[j].ss);
                E.push_back({i,j,sqrt(d)});
            }
        }
        MST m = MST(E,n,r);
        cout<<"Case #"<<cas+1<<": "<<m.states<<" "<<round(m.d1)<<" "<<round(m.d2)<<"\n";
    }




    return 0;
}