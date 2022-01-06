#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n;


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
        cin>>n;
        int q; cin>>q;
        BIT2D b=BIT2D(n,n);
        string aux;

        rep(i,n){
            cin>>aux;
            rep(j,n)
                b.set(i+1,j+1,aux[j]-'A'+1);
        }
        
        while(q--){
            int op,x1,x2,y1,y2;
            string str;
            cin>>op;
            if(!op){
                cin>>x1>>y1>>str;
                if(x1==0) 
                    rep(i,n)
                        b.set(y1+1,i+1,str[i]-'A'+1);
                else 
                    rep(i,n)
                        b.set(i+1,y1+1,str[i]-'A'+1);
            }
            else{
                cin>>x1>>y1>>x2>>y2;
                cout<<b.sum(x1+1,y1+1,x2+1,y2+1)<<"\n";
            }
        }
    }



    return 0;
}