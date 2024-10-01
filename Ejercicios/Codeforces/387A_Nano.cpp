#include<bits/stdc++.h>
using namespace std;
int main(){
  int mini,segi;
  string asd;
  getline(cin,asd);
  mini= 10*(asd[0]-'0')+asd[1]-'0';
  segi= 10*(asd[3]-'0')+asd[4]-'0';
  int mindor,segdor;
  getline(cin,asd);
  mindor=10*(asd[0]-'0')+asd[1]-'0';
  segdor=10*(asd[3]-'0')+asd[4]-'0';
  //cout<<mini<<" "<<segi<<" "<<endl<<mindor<<" "<<segdor<<endl;

  int tiemp=  60*mini+segi -60*mindor-segdor;
  if (tiemp<0){
    tiemp += 24*60;
  }
  int minfin=tiemp/60;
  int segin=tiemp%60;

  if(minfin==0){
    cout<<"00:";
    if(segin==0){
      cout<<"00";
    }
    else if(log10(segin)<1){
      cout<<"0"<<segin;
    }
    else{
      cout<<segin;
    }
  }
  else if(log10(minfin)<1){
    cout<<"0"<<minfin<<":";
    if(segin==0){
      cout<<"00";
    }
    else if(log10(segin)<1){
      cout<<"0"<<segin;
    }
    else{
      cout<<segin;
    }
  }
  else{
    cout<<minfin<<":";
    if(segin==0){
      cout<<"00";
    }
    else if(log10(segin)<1){
      cout<<"0"<<segin;
    }
    else{
      cout<<segin;
    }
  }
  cout<<endl;





  return 0;
}
