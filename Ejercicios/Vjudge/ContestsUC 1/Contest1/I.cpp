#include<bits/stdc++.h>
using namespace std;
typedef pair<vector<string>,vector<string> > vsvs;
typedef pair<vsvs,map<int,string> > par;
int main(){
  string command;
  string word;
  vector<string> words;
  int ent;
  char op;
  map<string,int> mapa;
  map<int,string> map2;
  vector<pair<par, int> > ans;

  while(cin>>command){
    if(command=="def"){
      cin>>word;
      cin>>ent;
      if(mapa.count(word)) {
        map2.erase(mapa[word]);
        mapa[word]=ent;
      }
      else {
        mapa.insert(pair<string,int>(word,ent));
      }

      if(map2.count(ent)){
        map2[ent]=word;
      }
      else{
        map2.insert(pair<int,string>(ent,word));
      }
    }

    else if(command=="calc"){
      bool yeah=true;
      int anss=0;
      string com;
      vector<string> comm;
      vector<string> pal;
      bool change=true;

      while(cin>>word){
        if(change) pal.push_back(word);
        else comm.push_back(word);
        change= !change;
        if(word=="=") break;
      }

      bool dentro=false;
      for(int i=0;i<pal.size();i++){
        if(!mapa.count(pal[i])){
          //cout<<"pal[i]: "<<pal[i]<<endl;
          anss=INT_MIN;
          dentro=true;
          ans.push_back(pair<par, int> (par(vsvs(pal,comm),map2),anss));
          break;
        }
        int aux=mapa[pal[i]];
        if(i>0){
          if(comm[i-1]=="-") aux*=-1;
        }
        anss+=aux;
      }
      if(!dentro){
        ans.push_back(pair<par, int> (par(vsvs(pal,comm),map2),anss));
      }
    }
    else if(command=="clear"){
      mapa.clear();
      map2.clear();
    }
  }

  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].first.first.first.size();j++){
      cout<<ans[i].first.first.first[j]<<" "<<ans[i].first.first.second[j]<<" ";
    }
    //cout<<ans[i].second<<endl;
    if(!ans[i].first.second.count(ans[i].second)){
      cout<<"unknown"<<endl;
    }
    else{
      cout<<ans[i].first.second[ans[i].second]<<endl;
    }
  }


  return 0;
}
