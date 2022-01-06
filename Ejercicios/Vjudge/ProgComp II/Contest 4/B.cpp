#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

struct Tree{
    vector<vector<int>> g;
    vector<ll> p;
    vector<ll> peso;
    vector<ll> STmin, STacc, L;
    vector<ll> c,tin,tout; 
    int n;
    int id=0;
    Tree(int a){
        n=a;
        g.assign(n+3,vector<int>());
        L.assign(4*n,0);
        p.resize(n+3);
        peso.resize(n+3);
        STacc.resize(4*n);
        STmin.resize(4*n);
        c.resize(n+2); tin.resize(n+2); tout.resize(n+2);
        int ui, si;
        for(int i=1;i<=n;i++){
            cin>>ui>>si;
            peso[i]=si;
            p[i]=ui;
            if(ui!=0) g[ui].push_back(i);
        }
        dfs(1);
        build(1,0,n-1);
    }

    void dfs(int u){
        c[id]=peso[u];
        id++;
        tin[u]=id;
        for(auto& v:g[u])
            dfs(v);
        tout[u]=id;
        return;
    }

    void build(ll node, ll l, ll r){
        if(l==r){
            STmin[node]=c[l];
            STacc[node]=c[l];
            return;
        }
        build(2*node,l,(l+r)/2);
        build(2*node+1,(l+r)/2+1,r);
        STmin[node]=min({ll(1000),STmin[2*node],STmin[2*node+1]});
        STacc[node]=STacc[2*node]+STacc[2*node+1];
        return;
    }

    ll minq(ll v){
        return minq(1,0,n-1,tin[v]-1,tout[v]-1);
    }

    ll minq(ll node, ll l, ll r, ll i, ll j){
        if(L[node]!=0){
            STmin[node]+=L[node];
            STacc[node]+=L[node]*(r-l+1);
            if(l!=r){
                L[2*node]+=L[node];
                L[2*node+1]+=L[node];
            }
            L[node]=0;
        }
        if(r<i || j<l) return ll(1000);
        if(i<=l && r<=j) return STmin[node];
        ll op1=minq(2*node,l,(l+r)/2,i,j);
        ll op2=minq(2*node+1,(l+r)/2+1,r,i,j);
        return min({op1,op2,ll(1000)});
    }

    ll accq(ll v){
        return accq(1,0,n-1,tin[v]-1,tout[v]-1);
    }

    ll accq(ll node, ll l, ll r, ll i, ll j){
        if(L[node]!=0){
            STmin[node]+=L[node];
            STacc[node]+=L[node]*(r-l+1);
            if(l!=r){
                L[2*node]+=L[node];
                L[2*node+1]+=L[node];
            }
            L[node]=0;
        }
        if(r<i || j<l) return 0;
        if(i<=l && r<=j) return STacc[node];
        ll ans=accq(2*node,l,(l+r)/2,i,j);
        ans+=accq(2*node+1,(l+r)/2+1,r,i,j);
        return ans;
    }
    
    void update(ll v){
        update(1,0,n-1,tin[v]-1,tout[v]-1,minq(v));
        return;
    }

    void update(ll node, ll l, ll r, ll i, ll j, ll x){ 
        if(L[node]!=0){
            STacc[node]+=L[node]*(r-l+1);
            STmin[node]+=L[node];
            if(l!=r){
                L[2*node]+=L[node];
                L[2*node+1]+=L[node];
            }
            L[node]=0;
        }
        if(i<=l && r<=j){
            STacc[node]+=x*(r-l+1);
            STmin[node]+=x;
            if(l!=r){
                L[2*node]+=x;
                L[2*node+1]+=x;
            }
            return;
        }
        if(r<i || j<l) return;
        update(2*node,l,(l+r)/2,i,j,x);
        update(2*node+1,(l+r)/2+1,r,i,j,x);
        STmin[node]=min({ll(1000),STmin[2*node],STmin[2*node+1]});
        STacc[node]=STacc[2*node]+STacc[2*node+1];
        return;
    }

};




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    rep(cas,t){
        int n,q; cin>>n>>q;
        Tree tree=Tree(n);
        int c,v;
        cout<<"Case "<<cas+1<<":\n\n";
        while(q--){
            cin>>c>>v;
            if(c==1){
                cout<<tree.accq(v)<<"\n\n";
            }
            else{
                tree.update(v);
            }
        }
    }


    return 0;
}