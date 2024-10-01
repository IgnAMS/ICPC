#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        string linea; cin>>linea;
        int n=linea.length();
        int cont=0;
        int low=0;
        deque<char> d1;
        d1.push_back(linea[0]);
        for(int i=1;i<n;i++){
            if(!d1.empty() && d1.back()=='A' && linea[i]=='B'){
                cont+=2;
                d1.pop_back();
                i++;
                while(!d1.empty() && i<n && d1.back()=='A' && linea[i]=='B'){
                    d1.pop_back();
                    i++;
                    cont+=2;
                }
            }
            if(i<n) d1.push_back(linea[i]);
        }
        
        linea="";
        while(!d1.empty()) { linea+=d1.front(); d1.pop_front(); }
        n=linea.length();
        if(linea.length()>0) d1.push_back(linea[0]);
        for(int i=1;i<n;i++){
            if(!d1.empty() && d1.back()=='B' && linea[i]=='B'){
                cont+=2;
                d1.pop_back();
                i++;
                while(!d1.empty() && i<n && d1.back()=='B' && linea[i]=='B'){
                    d1.pop_back();
                    i++;
                    cont+=2;
                }
            }
            if(i<n) d1.push_back(linea[i]);
        }
        cout<<d1.size()<<"\n";
        //for(char i: d1) cout<<i<<" "; cout<<"\n";
    }




    return 0;
}