#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string linea;
    map<string,int> m1;
    map<int,string> m2;
    while(getline(cin,linea)){
        vector<string> L;
        string aux="";
        rep(i,linea.length()){
            if(linea[i]==' ') { L.push_back(aux); aux=""; }
            else aux+=linea[i];
        }
        L.push_back(aux);
        if(L[0]=="def"){
            int c=0;
            bool neg=0;
            for(int i=0;i<L[2].length();i++){
                if(L[2][i]=='-') neg=1;
                else c=c*10+L[2][i]-'0';
            }
            if(neg) c*=-1;
            if(m1.count(L[1])) m2.erase(m1[L[1]]);
            m1[L[1]]=c;
            m2[c]=L[1];
        }
        else if(L[0]=="calc"){
            int c=0;
            bool no=0;
            for(int i=1;i<L.size();i++) cout<<L[i]<<" ";

            for(int i=1;i<L.size()-1;i++){
                if(L[i]=="-" || L[i]=="+"){
                    if(m1.count(L[i+1])) c+=(L[i]=="-"? -m1[L[i+1]]:m1[L[i+1]]);
                    else { no=1; break; }
                    i++;
                }
                else {
                    if(m1.count(L[i])) c+=m1[L[i]];
                    else { no=1; break; }
                }
            }
            if(!m2.count(c)) no=1;
            if(no) cout<<"unknown\n";
            else cout<<m2[c]<<"\n";
        }
        else{
            m1.clear(); m2.clear();
        }

            
    }


    return 0;
}