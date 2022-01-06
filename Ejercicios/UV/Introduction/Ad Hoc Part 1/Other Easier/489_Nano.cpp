#include<bits/stdc++.h>
using namespace std;

vector<bool> visit(27,true);
bool fastcheck(){
  bool state=true;
  for(int i=0;i<27;i++){
    if(!visit[i]){
      state=false;
      break;
    }
  }
  return state;
}

int main(){
  int t;
  string linea1,linea2;
  while(cin>>t){
    if(t==-1) break;
    vector<bool> abc(27,false);
    visit.assign(27,true);
    int cont=0;
    cin>>linea1>>linea2;
    bool win=false;

    for(int i=0;i<linea1.length();i++){
      abc[linea1[i]-'a']=true;
      visit[linea1[i]-'a']=false;
    }

    for(int i=0;i<linea2.length();i++){
      if(!abc[linea2[i]-'a']){
        cont++;
        abc[linea2[i]-'a']=true;
      }
      if(cont>=7){
        win=false;
        break;
      }
      if(!visit[linea2[i]-'a']){
        visit[linea2[i]-'a']=true;
        if(fastcheck()){
          win=true;
          break;
        }
      }
    }
    if(win) printf("Round %d\nYou win.\n",t);
    else if(!win && cont<7) printf("Round %d\nYou chickened out.\n",t);
    else if(!win && cont>=7) printf("Round %d\nYou lose.\n",t);

  }




  return 0;
}
