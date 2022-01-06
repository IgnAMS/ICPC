#include<bits/stdc++.h>
using namespace std;
typedef pair<string,double> sd;

int main(){
  int p,g;
  cin>>p>>g;
  map<string,double> mapa;
  string algo;
  double otro;
  for(int i=0;i<p;i++){
    cin>>algo>>otro;
    mapa.insert(sd(algo,otro));
  }
  string linea;
  vector<bool> ohyeah;
  for(int i=0;i<g;i++){
    //printf("\n\nestamos en el caso %d\n",i+1);
    vector<string> parties;
    string comp;
    while(cin>>linea){
      if(linea=="+") continue;
      else if(linea==">" || linea== ">=" || linea== "<" || linea=="<=" || linea== "="){
        comp=linea;
        break;
      }
      else{
        parties.push_back(linea);
      }
    }
    double asd;
    cin>>asd;
    double help=0;
    for(int j=0;j<parties.size();j++){
      help+=mapa[parties[j]];
      //cout<<parties[i]<<" ";
    }
    //cout<<help<<" "<<comp<<" "<<asd<<endl;
    bool yes;
    if(comp==">"){
      if(help-asd>1e-9) yes=true;
      else yes=false;
    }
    else if(comp==">="){
      if(help-asd>=1e-9 || abs(help-asd)<1e-9) yes=true;
      else yes=false;
    }
    else if(comp=="<"){
      if(1e-9<asd-help) yes=true;
      else yes=false;
    }
    else if(comp=="<="){
      if(1e-9<=asd-help || abs(help-asd)<1e-9) yes=true;
      else yes=false;
    }
    else if(comp=="="){
      if(abs(help-asd) < 1e-9){
        yes=true;
        //cout<<"xdddd"<<endl;
      }
      else yes=false;
    }
    ohyeah.push_back(yes);
    //cout<<endl<<asd<<"  "<<comp<<"  "<<help<<endl;
    //printf("\nPara el caso %d la diferencia es %f\n",i+1,help-asd);
  }
  for(int i=0;i<ohyeah.size();i++){
    if(ohyeah[i]){
      printf("Guess #%d was correct.\n",i+1);
    }
    else{
      printf("Guess #%d was incorrect.\n",i+1);
    }
  }

  return 0;
}
