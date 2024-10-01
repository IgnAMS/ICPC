#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;



int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int n; cin>>n;
    int out=0, in=0;
    char c;
    int aux;
    bool flag=0;
    deque<int> asd(n,-1);
    vector<int> pos;
    set<int> maxi;
    rep(i,n) for(int i=0;i<n;i++) maxi.insert(i+1);
    set<int>::reverse_iterator it = maxi.rbegin();
    //cout<<*it<<"\n";
    bool neg=0;
    rep(i,2*n){
        if(!neg) cin>>c;
        if(c=='+') { 
            in++;
            pos.push_back(in-1); 
            it++;
        }
        else{
            int ant=0;
            while(c=='-'){
                out++;
                if(in-out<0) { flag=1; break; }
                cin>>aux;
                if(aux<ant) {flag=1; break;}
                ant=aux;
                it--;
                //cout<<aux<<" "<<(*it)<<"\n";
                //cerr<<"vivo xd\n";
                if(aux>(*it)) { flag=1; break; }
                maxi.erase(aux);
                asd[pos.back()]=aux;
                pos.pop_back();
                i++;
                if(i<=2*n) cin>>c;
                else break;
            }
            neg=true;
            i--;
            if(flag) break;
        }
    }
    

    if(flag) { cout<<"NO\n"; return 0; } 
    cout<<"YES\n";
    rep(i,n) cout<<asd[i]<<" ";
    cout<<"\n";

    return 0;
}