#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second
#define mp make_pair

struct MST{
    int comps;
    vector<int> p,size;
    int n; 
    double minr=0,minR=0;

    map<int,int> pstate;
    map<int,int> sstate;
    vector<pair<double,ii>> states;

    vector<int> pcit,scit;

    MST(vector<ii>& A, double r){
        n=A.size();
        comps=n;
        p.resize(n);
        pcit.resize(n);
        scit.assign(n,1);
        size.assign(n,1);
        rep(i,n) {p[i]=i; pcit[i]=i;}

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                double dist=sqrt((A[i].ff-A[j].ff)*(A[i].ff-A[j].ff)+
                    (A[i].ss-A[j].ss)*(A[i].ss-A[j].ss));
                if(dist<=r)
                        join(i,j);
            }
        }
        //dado un componente me da un vector de doubles de las distancias

              
        rep(i,n){
            int x=find(i);
            if(!pstate.count(x)) {pstate.insert(mp(x,x));sstate.insert(mp(x,1));}
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && find(i)!=find(j)){
                    double dist=sqrt((A[i].ff-A[j].ff)*(A[i].ff-A[j].ff)+
                        (A[i].ss-A[j].ss)*(A[i].ss-A[j].ss));
                    states.push_back(mp(dist,mp(find(i),find(j))));
                }
            }
        }

        sort(states.begin(),states.end());
        rep(i,states.size()){
            joinstate(states[i].ss.ff,states[i].ss.ss,states[i].ff);
        }

        vector<pair<double,ii>> road;
        for(int i=0;i<n;i++){
            int x=find(i);
            for(int j=0;j<n;j++){
                if(i!=j && x==find(j)){
                    double dist=sqrt((A[i].ff-A[j].ff)*(A[i].ff-A[j].ff)+
                        (A[i].ss-A[j].ss)*(A[i].ss-A[j].ss));
                    road.push_back(mp(dist,mp(i,j)));
                    
                }
            }
        }

        sort(road.begin(),road.end());
        rep(i,road.size()){
            joincity(road[i].ss.ff,road[i].ss.ss,road[i].ff);
        }
    }

    int find(int u){
        return p[u]==u? u:p[u]=find(p[u]);
    }

    void join(int u, int v){
        u=find(u), v=find(v);
        if(u==v) return;
        comps--;
        if(size[v]>size[u]) swap(u,v);
        size[u]+=size[v];
        p[v]=u;
    }

    int findstate(int u){
        return pstate[u]==u? u:pstate[u]=findstate(pstate[u]);
    }
    void joinstate(int u, int v, double w){
        u=findstate(u),v=findstate(v);
        if(u==v) return;
        minR+=w;
        if(sstate[v]>sstate[u]) swap(u,v);
        sstate[u]+=sstate[v];
        pstate[v]=u;
    }
    
    int findcit(int u){
        return pcit[u]==u? u:pcit[u]=findcit(pcit[u]);
    }
    
    void joincity(int u, int v, double w){
        u=findcit(u),v=findcit(v);
        if(u==v) return;
        minr+=w;
        if(scit[v]>scit[u]) swap(u,v);
        scit[u]+=scit[v];
        pcit[v]=u;
    }

};


int main(){
    int t; cin>>t;
    rep(cas,t){
        int n; 
        double r;
        cin>>n>>r;
        vector<ii> A(n);
        rep(i,n) cin>>A[i].ff>>A[i].ss;
        MST mst=MST(A,r);
        cout<<"Case #"<<cas+1<<": "<<mst.comps<<" "<<round(mst.minr)<<" "<<round(mst.minR)<<"\n";
    }


 

    return 0;
}