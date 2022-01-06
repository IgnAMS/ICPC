#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second

struct BIT2D{
    vector<vector<ll>> bit;
    int R,C;
    BIT2D(int _R, int _C): R(_R+1), C(_C+1){
        bit.assign(R,vector<ll>(C,0));
    }

    void add(int r, int c, ll value){
        for(int i=r; i<R; i += (i&-i))
            for(int j=c; j<C; j += (j&-j))
                bit[i][j] += value;
        return;
    }

    ll sum(int r, int c){
        ll res=0;
        for(int i=r; i; i -= (i&-i))
            for(int j=c; j; j -= (j&-j))
                res+=bit[i][j];
        return res;
    }

    ll sum(int r1, int c1, int r2, int c2){
        return (sum(r2,c2)-sum(r1-1,c2)-sum(r2,c1-1)+sum(r1-1,c1-1));
    }

    ll get(int r, int c) {
        return sum(r, c, r, c);
    }

    void set(int r, int c, ll value) {
        add(r, c, -get(r, c) + value);
        return;
    }
    ll pos(int r, int c){
        return bit[r][c];
    }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        BIT2D mat = BIT2D(n,n);
        string linea;
        while(cin>>linea){
            if(linea=="END") break;
            int r1,c1,r2,c2;
            ll c;
            //cout<<linea<<"\n";
            if(linea=="SET"){
                cin>>r1>>c1>>c;
                mat.set(r1+1,c1+1,c);
                //cout<<"mat: "<<mat.get(r1+1,c1+1)<<" "<<mat.pos(r1+1,c1+1)<<"\n";
                //cout<<mat.pos(0,0)<<" "<<mat.pos(1,0)<<" "<<mat.pos(0,1)<<" "<<mat.pos(1,1)<<"\n";
            }

            if(linea=="SUM"){
                cin>>r1>>c1>>r2>>c2;
                cout<<mat.sum(r1+1,c1+1,r2+1,c2+1)<<"\n";
            }
        }



    }




    return 0;
}