#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(int i=a;i<b;i++)


ll aux=0;
vector<int> ans;


void backtrack(int s, int m){
    //cout<<aux<<" "<<m<<endl;
    if(m==1){
        aux+=s;
        ans.push_back(aux);
        aux-=s;
        return;
    }
    rep(i,0,s+1){
        aux+=i;
        aux*=10;
        backtrack(s-i,m-1);
        aux/=10;
        aux-=i;
        if(ans.size()>int(1e4+3)) return;
    }

    return;
}


int main(){
    int dig=2;
    
    while(ans.size()<=int(1e4+3)){
        rep(i,1,10){
            aux+=i;
            aux*=10;
            backtrack(10-i,dig-1);
            if(ans.size()>int(1e4+3)){
                break;
            }
            aux/=10;
            aux-=i;
        }
        dig++;
    }

    int n; cin>>n;
    cout<<ans[n-1]<<endl;
    
    


    return 0;
}