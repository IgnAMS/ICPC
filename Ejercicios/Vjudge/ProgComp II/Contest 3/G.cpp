#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

struct SegTree{
    int n,a;
    vector<int> ST;
    SegTree(vector<int>& A, int a){
        n=A.size();
        ST.resize(4*n);
        this->a=a;
        build(1,0,n-1,a,A);
    }
    void build(int node, int l, int r, int a, vector<int>& A){
        if(l==r){
            ST[node]=A[l];
            return;
        }
        build(node*2,l,(l+r)/2,a-1,A);
        build(node*2+1,(l+r)/2+1,r,a-1,A);
        if(a%2==1)
            ST[node]=ST[2*node] | ST[2*node+1];
        else
            ST[node]=ST[2*node] ^ ST[2*node+1];
        //cout<<node<<", "<<ST[node]<<"\n";
        return;
    }
    void update(int i, int v){
        return update(1,0,n-1,a,i,v);
    }
    void update(int node, int l, int r, int a, int i, int v){
        if(r<i || i<l) return;
        if(l==r){
            ST[node]=v;
            return;
        }
        update(2*node,l,(l+r)/2,a-1,i,v);
        update(2*node+1,(l+r)/2+1,r,a-1,i,v);
        if(a%2==1)
            ST[node]=ST[2*node] | ST[2*node+1];
        else
            ST[node]=ST[2*node] ^ ST[2*node+1];
        //cout<<node<<", "<<ST[node]<<"\n";
        return;    
        
    }
    int printv(){
        return ST[1];
    }
};



int main(){
    int n,m; cin>>n>>m;
    int asd=(1<<n);
    vector<int> A(asd);
    rep(i,asd){
        cin>>A[i];
    }
    //for(auto& v: A) cout<<v<<" "; cout<<"\n";
    SegTree ST=SegTree(A,n);
    while(m--){
        int u,v;
        cin>>u>>v;
        ST.update(u-1,v);
        cout<<ST.printv()<<"\n";
    }



    return 0;
}