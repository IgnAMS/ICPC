#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int minx=100, miny=100, maxx=-100, maxy=-100;

bool check1(int a, int b){
    return minx<=a && a<=maxx && miny<=b && b<=maxy;
}

int c1=-1000, c2=-1000, c3=-1000, c4=-1000;

bool check2(int a, int b){
    return ((b-a<=c1) == (b-a>=c2)) && ((a+b<=c3) == (a+b>=c4));
}


int main(){
    int A[8]; rep(i,8) cin>>A[i];
    int B[8]; rep(i,8) cin>>B[i];
    rep(i,4) minx=min(minx, A[2*i]), miny=min(miny, A[2*i+1]);
    rep(i,4) maxx=max(maxx, A[2*i]), maxy=max(maxy, A[2*i+1]);
    rep(i,4){
        bool pos = (B[2*i]-B[(2*(i+1))%8]) * (B[2*i+1]-B[(2*(i+1)+1)%8]) > 0? 1: 0;
        if(pos){
            if(c1 == -1000) c1 = B[2*i+1] - B[2*i];
            else c2 = B[2*i+1] - B[2*i];
        }
        else{
            if(c3==-1000) c3 = B[2*i+1] + B[2*i];
            else c4 = B[2*i+1] + B[2*i];
        }
    }
    int aux=c1; c1=max(c1,c2); c2=min(aux,c2);
    aux=c3; c3=max(c3,c4); c4=min(aux,c4);

    repx(i,-100,101) repx(j, -100, 101){
        if(check1(i,j) && check2(i,j)) { cout<<"YES\n"; return 0; }
    }

    cout<<"NO\n";
    return 0;
}