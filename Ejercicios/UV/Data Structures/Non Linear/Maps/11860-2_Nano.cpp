#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  getchar();
  int doc=0;
  while(t--){
    doc++;
    string linea;
    vector<string> palabras;
    map<string,int> mapa;
    map<string,int> conts;
    map<string,int> conts2;
    int cont=0;
    while(getline(cin,linea)){
      if(linea=="END") break;
      string aux="";
      for(int i=0;i<linea.length();++i){
        if('a'<=linea[i] && linea[i]<='z'){
          aux+=linea[i];
        }
        else{
          if(aux=="") continue;
          if(!mapa.count(aux)){
            mapa.insert(make_pair(aux,cont));
            cont++;
            conts.insert(make_pair(aux,0));
            conts2.insert(make_pair(aux,0));
          }
          conts[aux]++;
          //conts2[aux]++;
          palabras.push_back(aux);
          aux="";
        }
      }
      if(aux!=""){
        if(!mapa.count(aux)){
          mapa.insert(make_pair(aux,cont));
          cont++;
          conts.insert(make_pair(aux,0));
          conts2.insert(make_pair(aux,0));
        }
        conts[aux]++;
        //conts2[aux]++;
        palabras.push_back(aux);
        aux="";
      }
    }

    int low=0;
    int p=0,q=palabras.size()-1;
    map<string,int> conta;
    for(int i=0;i<palabras.size();i++){
      if(!conta.count(palabras[i])){
        conta.insert(make_pair(palabras[i],0));
      }
      conta[palabras[i]]++;
      while(conta[palabras[low]]>1){
        conta[palabras[low]]--;
        low++;
      }
      //printf("low: %d, top: %d, cond; %d\n",low,i,i-low<q-p && conta.size()==conts2.size());
      if((i-low)<(q-p) && conta.size()==conts2.size()){
        //cout<<"ahhh entre a esta condicion pibe\n";
        p=low;
        q=i;
      }
      else if(i-low==q-p && low<p && conts2.size()==conta.size()){
        p=low;
        q=i;
      }
    }
    printf("Document %d: %d %d\n",doc,p+1,q+1);
  }


  return 0;
}
