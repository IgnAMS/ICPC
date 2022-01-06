#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string linea; cin>>linea;
    map<int,int> mapa;
    vector<int> vec;
    int cont=0;
    for(int i=0;i<linea.length();i++){
        if(linea[i]=='(') { 
            vec.push_back(i);
            mapa[i] = cont++; //esta asociado con el 1 
        }
        if(linea[i]==')'){
            mapa[i] = mapa[vec.back()];
            vec.pop_back(); 
        }
    }
    set<string> ans;
    for(int i=0;i<(1<<cont)-1;i++){
        string aux="";
        for(int j=0;j<linea.length();j++){
            if(linea[j]==')' || linea[j]=='('){
                if(i & (1<<mapa[j])) aux+=linea[j];
            }
            else aux+=linea[j];
        }
        ans.insert(aux);
    }

    for(auto& u: ans){
        cout<<u<<"\n";
    }

    return 0;
}