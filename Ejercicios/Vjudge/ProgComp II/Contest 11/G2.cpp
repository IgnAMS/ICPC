#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
#define ff first.first
#define ss first.second
#define tt second


int main(){
    int l,h,r;
    vector<iii> E;
    while(cin>>l>>h>>r){
        E.push_back({{0,l},h});
        E.push_back({{1,r},h});
    }
    sort(E.begin(),E.end(),[&](const iii &a, const iii &b){
        if(a.ss==b.ss){
            if(a.ff==b.ff)
                return a.ff==0? b.tt<a.tt: a.tt<b.tt;
            return a.ff<b.ff;
        }
        return a.ss<b.ss;
    });
    multiset<int> s;
    int lastx;
    bool inicio=0;
    //for(auto& u: E) cout<<u.ff<<" "<<u.ss<<" "<<u.tt<<"\n";
    for(auto& u: E){
        if(u.ff==0){
            if(s.empty()) lastx=u.ss;
            else if(u.tt>*s.rbegin()){
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
                lastx=u.ss;
            }
        }
    }
    cout<<"\n";
}