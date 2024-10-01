#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

string linea;
int n;
bool cond1(int i, int x){
    if(i<x) return 0;
    return linea[i-x]=='1'? 1:0; 
}

bool cond2(int i, int x){
    if(i+x>=n) return 0;
    return linea[i+x]=='1'? 1:0;
}

int main(){
    int t; cin>>t;
    while(t--){
        int x;
        cin>>linea>>x;
        n=linea.length();
        bool yea=true;
        string aux="";
        rep(i,n){
            if(!cond1(i,x) && !cond2(i,x)){
                aux+='0';
            }
            else if((cond1(i,x) && !cond2(i,x)) || (!cond1(i,x) && cond2(i,x))){
                yea=false;
                break;
            }
            else if(cond1(i,x) && cond2(i,x)){
                aux+='1';
            }
        }
        if(yea){
            cout<<aux<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    



    return 0;
}