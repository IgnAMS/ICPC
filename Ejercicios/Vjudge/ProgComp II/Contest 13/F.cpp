#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int,int> ii;
#define ff first
#define ss second

struct e{
    int s, cost, en; //size, cost, enemy 
    e(int s, int cost, int en): s(s), cost(cost), en(en) {}
};

vector<vector<ii>> g;

struct G{
    vector<int> D,P;
    vector<ii> R;
    int d,p,r;
    vector<int> pD,pP,tDP,tPD;
    vector<e> G1,G2;
    int s1,s2;
    int bud;
    vector<vector<int>> dp1, dp2;
    G(vector<int>& A, vector<int>& B,vector<ii>& C, int budget){
        bud=budget;
        D=A; P=B; R=C; d=A.size(); p=B.size(); r=C.size();
        pD.assign(d,-1); pP.assign(p,-1);
        tDP.assign(d,-1); tPD.assign(p,-1);
        for(auto u: R) comp(u.ff,u.ss);

        vector<int> aux1(d,0),aux2(p,0); 
        s1=0,s2=0;
        int cont=0;
        rep(u,d) if(pD[u]<0) { aux1[u]=cont++;}
        cont=0;
        rep(u,p) if(pP[u]<0) { aux2[u]=cont++;}
        
        //armo el grafo xd
        rep(u,d) if(pD[u]<0) 
            G1.emplace_back(-pD[u],D[u], (tDP[u]==-1? -1:aux2[tDP[u]]));
        rep(u,p) if(pP[u]<0)
            G2.emplace_back(-pP[u],P[u], (tPD[u]==-1? -1:aux1[tPD[u]]));  

        dp1.assign(101,vector<int>(int(1e4)+2,-1)); 
        dp2.assign(101,vector<int>(int(1e4)+2,-1));
        //printG();
        cout<<DP1(0,bud,d)<<" "<<DP2(0,bud,p)<<"\n";
    }

    void comp(int u, int v){
        u=findd(u), v=findp(v);
        if(tPD[v] != -1){ if(tPD[v]!=u){
            int a = tPD[v], b = u;
            if(-pD[a] > -pD[b]) swap(a,b);
            //cerr<<"D: "<<b<<" es padre de "<<a<<"\n";
            pD[b]+=pD[a]; pD[a]=b;
            D[b]+=D[a];
            tPD[v]=b;
        } }
        else tPD[v]=u;
        
        tPD[v]=findd(tPD[v]);

        if(tDP[u] != -1){ if(tDP[u]!=v){
            int a = tDP[u], b = v;
            if(-pP[a] > -pP[b]) swap(a,b);
            //cerr<<"P: "<<b<<" es padre de "<<a<<"\n";
            pP[b]+=pP[a]; pP[a]=b;
            P[b]+=P[a];
            tDP[u]=b;
        } }
        else tDP[u]=v;
        tDP[u]=findp(tDP[u]);
    }

    void printG(){
        cout<<"D: \n";
        rep(u,d) if(pD[u]<0) cout<<u<<" es padre y tiene costo: "<<D[u]<<"\n";
        cout<<"P: \n";
        rep(u,p) if(pP[u]<0) cout<<u<<" es padre y tiene costo: "<<P[u]<<"\n";
    }

    int findp(int u){ return pP[u]<0? u:pP[u]=findp(pP[u]); }
    int findd(int u){ return pD[u]<0? u:pD[u]=findd(pD[u]); }


    int DP1(int x, int b, int s){ //x-> elemento, b->budget
        if(dp1[x][b]!=-1) return dp1[x][b];
        ii en= G2[x].en==-1? ii(0,0):ii(G1[G2[x].en].cost, G1[G2[x].en].s);
        if(x==G2.size()-1){
            dp1[x][b]=s;
            if(b>=G2[x].cost + en.ff){
                dp1[x][b]=max(int(s+G2[x].s-en.ss), s);
            }
            return dp1[x][b];
        }
        
        dp1[x][b]=DP1(x+1,b,s);
        if(b>=G2[x].cost + en.ff){
            dp1[x][b]=
                max(DP1(x+1,b-G2[x].cost-en.ff,s)+G2[x].s-en.ss, dp1[x][b]);
        }
        return dp1[x][b];   
    }

    int DP2(int x, int b, int s){ //x-> elemento, b->budget
        if(dp2[x][b]!=-1) return dp2[x][b];
        ii en= G1[x].en==-1? ii(0,0):ii(G2[G1[x].en].cost,G2[G1[x].en].s);
        if(x==G1.size()-1){
            dp2[x][b]=s;
            if(b>=G1[x].cost + en.ff){ 
                dp2[x][b]=max(int(s+G1[x].s-en.ss), dp2[x][b]);
            }
            return dp2[x][b];
        }
        
        dp2[x][b]=DP2(x+1,b,s);
        if(b>=G1[x].cost + en.ff){
            dp2[x][b]=
                max(DP2(x+1,b-G1[x].cost-en.ff,s)+G1[x].s-en.ss, dp2[x][b]);
        }
        return dp2[x][b];   
    }


};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int d,p,r,b;
    while(cin>>d>>p>>r>>b){
        vector<int> D(d),P(p);
        vector<ii> R(r);
        rep(i,d) cin>>D[i];
        rep(i,p) cin>>P[i];
        rep(i,r) { cin>>R[i].ff>>R[i].ss; R[i].ff--, R[i].ss--; } 
        G(D,P,R,b);
    }


    return 0;
}