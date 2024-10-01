#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int q(int i){
    cout<<"? "<<i<<"\n"<<flush;
    //cerr<<"? "<<i<<"\n";
    int x;
    cin>>x;
    return x;
}
void ans(int i) { cout.flush()<<"! "<<i<<"\n"<<flush; }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    if(n<5){
        int l=1e6;
        int x=q(1);
        for(int i=2;i<n;i++){
            int r=q(i);
            if(l<x && x<r) { ans(i-1); return 0;}
            x=r;
        }
        if(l<x) ans(n);
        return 0;
    }
    int m, mi, mr;
    int i=0, j=n+1;
    int l=1e6, r=1e6;
    int mk=n/2;
    m=q(mk);
    if(m==1) { ans(mk); return 0; }
    while(i+2<j){
        if((i+mk)/2==i){
          int x=q((j+mk/2));
          if(m<x && x<r) { ans((j+mk)/2); return 0; }
          if(mi<m && m<x) { ans(mk); return 0; }
        }
        if((j+mk)/2==j){
          int x=q((i+mk)/2);
          if(l<x && x<m) { ans((i+mk)/2); return 0; }
          if(x<m && m<r) { ans(mk); return 0; }
        }
        mi= q((i+mk)/2);
        if(mi==1) { ans((i+mk)/2); return 0; }
        mr= q((j+mk)/2);
        if(mr==1) { ans((j+mk)/2); return 0; }
        //cerr<<"mi: "<<mi<<", mr: "<<mr<<"\n";
        if(l>mi && mi<m){
            int ja=j;
            j=mk; mk=(i+mk)/2; r=m; m=mi;
        }
        else if(l>mi && mi>m && m>mr){
            int ia=i;
            i=mk; mk=(j+mk)/2; l=m; m=mr;
        }
        else if((i+mk)/2==i)
        else if(mi>m && m<mr){
            i=(i+mk)/2; j=(j+mk)/2; l=mi, r=mr;
        }
        //cerr<<"i: "<<i<<", j: "<<j<<"\n";
    }
    ans(i+1);

    return 0;
}
