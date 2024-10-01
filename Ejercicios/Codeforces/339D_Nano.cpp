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
    vll ST;
    int state;
    SegmentTree(vll &A, int s){
        n=A.size();
        ST.resize(4*n);
        state=s;
        build(1,0,n-1,A,s);
    }
    void build(int node, int l, int r, vll &A, int a){
        if(l==r){
            ST[node]=A[l];
            return;
        }
        build(node*2,l,(l+r)/2,A,a-1);
        build(node*2+1,(l+r)/2+1,r,A,a-1);
        if(a%2==0){
            ST[node]= ST[node*2]^ST[node*2+1];
        }
        else
            ST[node]=(int(ST[node*2])|int(ST[node*2+1]));
        return;
    }
    void act(int i, ll x){
        return actu(1,0,n-1,i,x,state);
    }
    void actu(int node, int l, int r, int i, ll x, int a){
        if(i<l || r<i){
            return;
        }
        if(l==r){
            ST[node]=x;
            return;
        }
        actu(node*2,l,(l+r)/2,i,x,a-1);
        actu(node*2+1,(l+r)/2+1,r,i,x,a-1);
        if(a%2==0){
            ST[node]= ST[node*2] ^ ST[node*2+1];
        }
        else{
            ST[node]= ST[node*2] | ST[node*2+1];
        }
        /*
        cout<<"a vale: "<<a<<endl;
        printf("ST[%d] de %d hasta %d: %d",node,l,r,ST[node]);
        cout<<endl;
        */
        return;
    }
    ll printv(){
        return ST[1];
    }



};


int main(){
    //OJ;
    int n, m;
    cin>>n>>m;
    ll mult=1;
    mult<<=n;
    vll A(mult);
    for(int i=0;i<mult;i++){
        cin>>A[i];
    }
    SegmentTree ST(A,n);
    int a, b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        ST.act(a-1,b);
        cout<<ST.printv()<<endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}