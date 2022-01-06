#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

struct UF{
    vector<int> p,size;
    int n;
    UF(int a){
        n=a+1;
        p.resize(n); size.assign(n,1);
        rep(i,n) p[i]=i;
    }
    
    int find(int u){
        return p[u]==u? u:p[u]=find(p[u]);
    }
    bool same(int u, int v){
        return find(u)==find(v);
    }
    void join(int u, int v){
        int x=find(u),y=find(v);
        if(x==y) return;
        //cout<<"uno "<<x<<" con "<<y<<"\n";
        if(size[y]>size[x]) swap(x,y);
        size[x]+=size[y];
        p[y]=x;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,q; cin>>n>>q;
    char c; int a,b;
    UF uf=UF(n);
    while(q--){
        cin>>c>>a>>b;
        if(c=='?'){
            if(uf.same(a,b)) cout<<"yes\n";
            else cout<<"no\n";
        }
        else{
            uf.join(a,b);
        }
    }



    return 0;
}