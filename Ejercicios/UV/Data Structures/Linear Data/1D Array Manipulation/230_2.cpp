#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<string,bool> si;
typedef pair<si,string> sis; 
#define ff first
#define ss second
#define mp make_pair

int main(){
    ios::sync_with_stdio(0); cin.tie();
    vector<sis> libros;
    string comand, libro, by=" by ", who,linea;
    while(getline(cin,linea)){
        if(linea=="END") break;
        libro="", who="";
        rep(i,linea.length()){
            string aux="";
            rep(j,4) aux+=linea[i+j];
            //cout<<aux<<"\n";
            if(aux==" by "){
                for(int j=0;j<i;j++) libro+=linea[j];
                for(int j=i+4;j<linea.length();j++) who+=linea[j];
                break;
            }
        }
        //cout<<libro<<" "<<by<<" "<<who<<"\n";
        //pair<pair<string,bool>,string> a= pair<pair<string,bool>,string>(pair<string,bool>(libro,1),autor);
        libros.push_back(sis(si(libro,1),who));
    }
    sort(libros.begin(), libros.end(), [&](const sis& a, const sis& b){
        if(a.ss==b.ss) return a.ff.ff<b.ff.ff;
        return a.ss<b.ss;
    });

    map<string,int> id;
    rep(i,libros.size()) {
        id[libros[i].ff.ff]=i;
        //cout<<libros[i].ff.ff<<" "<<libros[i].ss<<"\n";
    }
    set<string> reponer;
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

        if(comand=="BORROW") libros[id[libro]].ff.ss=0;
        if(comand=="RETURN") reponer.insert(libro); 
        if(linea=="SHELVE") {
            string last=""; 
            rep(i,libros.size()){
                if(libros[i].ff.ss==0 && reponer.count(libros[i].ff.ff)){
                    if(last=="") cout<<"Put "<<libros[i].ff.ff<<" first\n";
                    else cout<<"Put "<<libros[i].ff.ff<<" after "<<last<<"\n";
                    //cerr<<"pongo el libro "<<libros[i].ff<<"\n";
                    libros[i].ff.ss=1;
                    reponer.erase(libros[i].ff.ff);
                }
                if(libros[i].ff.ss==1) last=libros[i].ff.ff;
            }
            cout<<"END\n";
        }
    }




    return 0;
}