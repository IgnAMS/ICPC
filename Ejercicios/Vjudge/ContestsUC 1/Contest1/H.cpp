#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef pair<char,ii> cii;
int main(){
  int t;
  cin>>t;
  map<char,pair<int,int> > pos;
  pos.insert(pair<char,ii>('q',ii(0,0)));
  pos.insert(pair<char,ii>('w',ii(0,1)));
  pos.insert(pair<char,ii>('e',ii(0,2)));
  pos.insert(pair<char,ii>('r',ii(0,3)));
  pos.insert(pair<char,ii>('t',ii(0,4)));
  pos.insert(pair<char,ii>('y',ii(0,5)));
  pos.insert(pair<char,ii>('u',ii(0,6)));
  pos.insert(pair<char,ii>('i',ii(0,7)));
  pos.insert(pair<char,ii>('o',ii(0,8)));
  pos.insert(pair<char,ii>('p',ii(0,9)));

  pos.insert(cii('a',ii(1,0)));
  pos.insert(cii('s',ii(1,1)));
  pos.insert(cii('d',ii(1,2)));
  pos.insert(cii('f',ii(1,3)));
  pos.insert(cii('g',ii(1,4)));
  pos.insert(cii('h',ii(1,5)));
  pos.insert(cii('j',ii(1,6)));
  pos.insert(cii('k',ii(1,7)));
  pos.insert(cii('l',ii(1,8)));

  pos.insert(cii('z',ii(2,0)));
  pos.insert(cii('x',ii(2,1)));
  pos.insert(cii('c',ii(2,2)));
  pos.insert(cii('v',ii(2,3)));
  pos.insert(cii('b',ii(2,4)));
  pos.insert(cii('n',ii(2,5)));
  pos.insert(cii('m',ii(2,6)));

  vector<map<int,vector<string> > > ans;
  map<int,vector<string> >::iterator it;
  while(t--){
    string linea;
    int n;
    map<int,vector<string> > mapa;
    cin>>linea>>n;
    string aux;
    for(int i=0;i<n;i++){
      int cont=0;
      cin>>aux;
      for(int j=0;j<aux.size();j++){
        cont+= abs(pos[linea[j]].first-pos[aux[j]].first)+abs(pos[linea[j]].second-pos[aux[j]].second);
      }
      if(!mapa.count(cont)){
        mapa.insert(pair<int,vector<string> > (cont,vector<string>()));
      }
      mapa[cont].push_back(aux);
    }
    for(it=mapa.begin();it!=mapa.end();++it){
      sort(it->second.begin(),it->second.end());
    }
    ans.push_back(mapa);
  }
  for(int i=0;i<ans.size();i++){
    for(it=ans[i].begin();it!=ans[i].end();++it){
        for(int j=0;j<it->second.size();j++){
          cout<<it->second[j]<<" "<<it->first<<endl;
        }
    }
  }

  return 0;
}
