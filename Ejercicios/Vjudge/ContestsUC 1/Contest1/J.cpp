#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<char> vec;
  char a;
  set<char> conj;
  map<char,int> mapa;
  for(int i=0;i<n;i++){
    cin>>a;
    vec.push_back(a);
    conj.insert(a);
    if(mapa.count(a)) mapa[a]++;
    else mapa.insert(pair<char,int>(a,1));
  }

  int i=0,j=0;
  int mini=10000000;
  map<char,int> aux;
  int cont=0;
  int previ=i;
  int prevj=j;
  aux.insert(pair<char,int>(vec[0],1));

  while(true){
    previ=i;
    prevj=j;
    //cout<<i<<" "<<j<<endl;
    if(conj.size()<=2){
      mini=conj.size();
      break;
    }

    if(aux.size()<mapa.size()){
      if(j<n-1){
        j++;
        //cout<<"estoy entrando aca? "<<vec[j]<<endl;;
        if(aux.count(vec[j])) aux[vec[j]]++;
        else aux.insert(pair<char,int> (vec[j],1));
      }
    }
    //cout<<"aux[i]: "<<aux[vec[i]]<<endl;
    if(i==vec.size()-1) break;

    while(aux[vec[i]]>1 && i<j){
      aux[vec[i]]--;
      i++;
    }
    /*for(map<char,int>::iterator it= aux.begin();it!=aux.end();it++){
      cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"aux.size: "<<aux.size()<<", mapa.size: "<<mapa.size()<<" con i: "<<i<<" y j: "<<j<<endl<<endl;
    */
    if(aux.size()==mapa.size()){
      //cout<<"son iguales\n";
      mini=min(mini,j-i+1);
      //cout<<"son iguales con i y j: "<<i<<" "<<j<<endl;

      if(i<vec.size() && i<j){
        //cout<<aux[vec[i]]<<endl;
        aux[vec[i]]--;
        if(aux[vec[i]]==0){
          aux.erase(vec[i]);
          //cout<<aux.size()<<" "<<mapa.size()<<endl;
        }
        //cout<<"aux.size luego de mover "<<aux.size()<<endl;
        i++;
      }
      else if(j<vec.size()-1){
        j++;
        if(aux.count(vec[j])) aux[vec[j]]++;
        else aux.insert(pair<char,int> (vec[j],0));
      }
      else{
        break;
      }
    }
    if(i==previ && j==prevj) cont++;
    if(cont==3) break;
  }
  cout<<mini<<endl;

  return 0;
}
