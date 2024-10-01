#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    string linea; cin>>linea;
    int n=linea.length();
    set<int> AB;
    set<int> BA;
    for(int i=0; i<n-1;i++){
        string aux=linea.substr(i,2);
        //cout<<aux<<endl;
        if(aux=="AB"){
            AB.insert(i);
            if(BA.size()>=2 || (BA.size() && *BA.begin() != i-1)){
                cout<<"YES"<<endl;
                return 0;
            }
        }
        if(aux=="BA"){
            BA.insert(i);
            if(AB.size()>=2 || (AB.size() && *AB.begin() != i-1)){
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    
    cout<<"NO"<<endl;


    return 0;
}