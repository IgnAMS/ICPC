#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;

#define INF (int)1e9
#define pb push_back
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

struct SegmentTree{
    int n;
    vll ST,open,closed;
    ll val=-3;
    SegmentTree(string &A){
        n=A.length();
        ST.resize(n*4);
        closed.assign(n*4,0);
        open.assign(n*4,0);
        build(1,0,n-1,A);
    }
    void build(int node, int l, int r, string &A){
        //si es hoja guarda el valor
        if(l==r){
            ST[node]=0;
            if(A[l] == ')') {
                closed[node]=1;
            }
            else{
                open[node]=1;
            }
            return;
        }
        //divide and conquer
        build(node*2,   l,(l+r)/2,A);
        build(node*2+1,(l+r)/2+1,r,A);

        ST[node]= min(open[node*2],closed[node*2+1])+ST[node*2]+ST[node*2+1];
        open[node]= open[node*2]+open[node*2+1]-ST[node]+ST[node*2]+ST[node*2+1];
        closed[node]= closed[node*2]+closed[node*2+1]-ST[node]+ST[node*2]+ST[node*2+1];
        return;
    }
    ll query(int i ,int j){
        return queryy(1,0,n-1,i,j);
    }
    ll queryy(int node, int l, int r, int i, int j){
        //si no pertence
        if(j<l || r<i){
            val=-3;
            return 0;
        }
        
        //si esta completamente contenido
        if(i<=l && r<=j){
            if(val!= -3){
                ll asd = min(val,closed[node]);
                val+= open[node]-asd;
                return ST[node]+asd;
            }
            val=open[node];
            return ST[node];
        }
        //divide and conquer
        return queryy(node*2,l,(l+r)/2,i,j)+queryy(node*2+1,(l+r)/2+1,r,i,j);
    }

};




int main(){
    //OJ;
    string linea;
    cin>>linea;
    SegmentTree ST(linea);
    int n;
    cin>>n;
    while(n--){
        int i,j;
        cin>>i>>j;
        cout<<2*ST.query(i-1,j-1)<<endl;
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}