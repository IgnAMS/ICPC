#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    bool a=false;
    bool b=false;
    bool c=false;
    int costaux;
    string aux;
    int minA=1e8,minB=1e8,minC=1e8;
    int minAB=1e8, minAC= 1e8, minBC=1e8;
    int minABC=1e8;
    rep(i,n){
        cin>>costaux>>aux;
        if(aux=="A"){
            minA=min(costaux,minA);
        }
        if(aux=="B"){
            minB=min(costaux,minB);
        }
        if(aux=="C"){
            minC=min(costaux,minC);
        }
        if(aux=="AB" || aux=="BA"){
            minAB=min(costaux,minAB);
        }
        if(aux=="AC" || aux=="CA"){
            minAC=min(costaux,minAC);
        }
        if(aux=="BC" || aux=="CB"){
            minBC=min(costaux,minBC);
        }
        if(aux.size()==3){
            minABC=min(costaux,minABC);
        }
    }
    int mini=1e8;
    mini=min(minA+minB+minC, mini);
    mini=min(minA+minBC, mini);
    mini=min(minB+minAC, mini);
    mini=min(minC+minAB, mini);
    mini=min({minAB+minBC, minAB+minAC, minAC+minBC, mini});
    mini=min(minABC,mini);
    if(mini==1e8) cout<<-1<<endl;
    else cout<<mini<<endl;    

    return 0;
}