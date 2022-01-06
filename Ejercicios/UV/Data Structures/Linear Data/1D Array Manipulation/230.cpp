#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<string,string> stst;
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie();
    unordered_map<string,string> autor;
    vector<string> libros;
    string comand, libro, by=" by ", who,linea;
    while(getline(cin,linea)){
        if(linea=="END") break;
        libro="", who="";
        rep(i,linea.length()-3){
            string aux=""; aux+=linea[i]; aux+=linea[i+1]; aux+=linea[i+2]; aux+=linea[i+3];
            //cout<<aux<<"\n";
            if(aux==" by "){
                for(int j=0;j<i;j++) libro+=linea[j];
                for(int j=i+4;j<linea.length();j++) who+=linea[j];
                break;
            }
        }
        //cout<<libro<<" "<<by<<" "<<who<<"\n";
        libros.push_back(libro);
        autor[libro]=who;
    }
    deque<stst> espera;
    set<string> quitar; //libros por quitar
    while(getline(cin,linea)){
        if(linea=="END") break;
        libro="", comand="";
        rep(i,linea.length()){
            if(linea[i]==' '){
                rep(j,i) comand+=linea[j];
                for(int j=i+1;j<linea.length();j++) libro+=linea[j];
                break;
            }
        }
        if(comand=="") comand=linea;
        if(comand=="BORROW") { quitar.insert(libro); }
        if(comand=="RETURN") { espera.push_back({autor[libro],libro}); }
        if(comand=="SHELVE") {
            sort(espera.begin(),espera.end(), [&](const stst& a, const stst& b){
                if(a.ff==b.ff) return a.ss<b.ss;
                return a.ff<b.ff;
            });
            while(!libros.empty() && quitar.count(libros.back()))
                libros.pop_back();
            
            if(libros.size()==0) { 
                //cerr<<"Put "<<espera.front().ss<<" first\n";
                cout<<"Put "<<espera.front().ss<<" first\n";
                libros.push_back(espera.front().ss);
                quitar.erase(espera.front().ss);
                espera.pop_front();
            }
            while(!espera.empty()){
                while(!libros.empty() && quitar.count(libros.back()))
                    libros.pop_back(); 
                //cerr<<"Put "<<espera.front().ss<<" after "<<libros.back()<<"\n";
                cout<<"Put "<<espera.front().ss<<" after "<<libros.back()<<"\n";
                libros.push_back(espera.front().ss);
                quitar.erase(espera.front().ss);
                espera.pop_front();
            }
            cout<<"END\n";
        }
    }




    return 0;
}