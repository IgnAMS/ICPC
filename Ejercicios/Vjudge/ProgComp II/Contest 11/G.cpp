#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define ff first.second
#define ss first.first
#define tt second


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    //vector<iii> E; //vector evento
    map<ii, int> Ev;
    //evento 0 abrir, 1 cerrar
    int l,h,r;
    while(cin>>l>>h>>r){
        if(Ev.count({l,0})) Ev[{l,0}]=max(h,Ev[{l,0}]);
        else Ev[{l,0}]=h;
        if(Ev.count({r,1})) Ev[{r,1}]=max(h,Ev[{r,1}]);
        else Ev[{r,1}]=h;
    }

    //for(auto& u: Ev) cerr<<u.ff<<" "<<u.ss<<" "<<u.tt<<"\n";
    multiset<int> s;
    int lastx;
    bool inicio=0;
    for(auto& u: Ev){
        if(u.ff==0) {
            if(s.empty()) lastx=u.ss;
            else if(*s.rbegin() < u.tt){
                if(inicio) cout<<" "; inicio=0;
                cout<<lastx<<" "<<*s.rbegin()<<" ";
                lastx=u.ss;
            }
            s.insert(u.tt);
        }

        else{
            int aux=*s.rbegin();
            s.erase(s.find(u.tt));
            if(s.empty()){
                if(inicio) cout<<" ";
                cout<<lastx<<" "<<aux<<" "<<u.ss<<" "<<0;
                inicio=1;
            }
                
            else if(aux>*s.rbegin()){
                if(inicio) cout<<" "; inicio=0;
                cout<<lastx<<" "<<aux<<" ";
                //cout<<u.ss<<"\n";
                lastx=u.ss;
            }
        }
    }
    cout<<"\n";
    


    return 0;
}