#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<string> L;
    string linea;
    int maxi=0;
    while(getline(cin,linea)) { L.push_back(linea); maxi=max(maxi,(int)linea.length()); }
    bool left=0;
    for(int i=0;i<maxi+2;i++) cout<<"*"; cout<<"\n";
    for(auto& u:L){
        cout<<"*";
        int d=maxi-u.length();
        if(d%2==0) {
            for(int i=0;i<d/2;i++) cout<<" ";
            cout<<u;
            for(int i=0;i<d/2;i++) cout<<" ";
        }
        else{
            for(int i=0;i<d/2+(left);i++) cout<<" ";
            cout<<u;
            for(int i=0;i<d/2+(!left);i++) cout<<" ";
            left=!left;
        }
        cout<<"*\n";
    }
    for(int i=0;i<maxi+2;i++) cout<<"*"; cout<<"\n";


    return 0;
}