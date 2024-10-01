#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int q(int i){ cout<<"? "<<i<<"\n"; int x; cin>>x; return x; }
void ans(int i) { cout<<"! "<<i<<"\n"; }

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
    int i=1, j=n;
    int l=1e6, r=1e6;
    m=q(i+j)/2;
    if(m==1) { ans((i+j)/2); return 0; } 
    while(i+1<j){
        mi= q(i+(j-i)/4), mr= q(i+3*(j-i)/4);
        if(mi==1) { ans(mi); return 0; }
        if(mr==1) { ans(mr); return 0; }
        if(l>mi && mi<m){
            j=i+(j-i)/4; r=m; m=mi;
        }
        if(l>mi && mi>m && m>mr){
            i=i+3*(j-i)/4; l=m; m=mr;
        }
    }
    







    return 0;
}