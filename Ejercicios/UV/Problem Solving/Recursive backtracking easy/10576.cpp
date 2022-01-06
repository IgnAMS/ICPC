#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;

int ans=-1;
vector<int> aux(12);
int s, d;
void backtrack(int x, int def){
    if(x==12){
        if(def==8){
            int sum=0;
            rep(i,0,12) sum+=aux[i];
            ans=max(ans,sum);
        }
        return;
    }
    aux[x]= -d;
    int h=0;
    bool oc=0;
    if(x>=4){
        rep(i,x-4,x+1) { h+=aux[i]; } 
        if(h<0) oc=1;
    }
    backtrack(x+1,def+oc);
    h=0;
    oc=0;
    aux[x]=s;
    if(x>=4){
        rep(i,x-4,x+1) h+=aux[i];
        if(h<0) oc=1;
    }
    backtrack(x+1,def+oc);
}


int main(){
    ios::sync_with_stdio(0);
    while(cin>>s>>d){
        ans=-1;
        backtrack(0,0);
        if(ans<0) cout<<"Deficit\n";
        else cout<<ans<<"\n";
    }

    return 0;
}