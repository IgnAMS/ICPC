#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  getchar();
  while(t--){
    getchar();
    string linea1,linea2;
    getline(cin,linea1);
    vector<int> pos;
    int maxi=0;
    int asd=0;
    for(int i=0;i<linea1.size();i++){
      if(linea1[i]==' ') {
        maxi=max(maxi,asd);
        pos.push_back(asd);
        asd=0;
      }
      else{
        asd=asd*10+linea1[i]-'0';
      }
      if(i==linea1.size()-1){
        maxi=max(maxi,asd);
        pos.push_back(asd);
        asd=0;
      }
    }

    getline(cin,linea2);
    vector<string> nums;
    string aux="";
    for(int i=0;i<linea2.size();i++){
      if(linea2[i]==' ') {
        nums.push_back(aux);
        aux="";
      }
      else{
        aux+=linea2[i];
      }
      if(i==linea2.size()-1){
        nums.push_back(aux);
        aux="";
      }
    }
    map<int,int> mapa;
    int cont=0;
    for(int i=0;i<maxi;i++){
      for(int j=0;j<pos.size();j++){
        if(pos[j]-1==cont){
          mapa.insert(pair<int,int>(cont,j));
          cont++;
        }
      }
    }
    for(int i=0;i<maxi;i++){
      cout<<nums[mapa[i]]<<endl;
    }

    if(t>0) cout<<endl;



  }



  return 0;
}
