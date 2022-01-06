#include<bits/stdc++.h>
using namespace std;

int main(){
  vector<vector<unsigned long long> > pot11(52,vector<unsigned long long>());
  pot11[0].push_back(1);
  pot11[1].push_back(1);
  pot11[1].push_back(1);

  for(int i=2;i<=50;i++){
    pot11[i].push_back(1);
    for(int j=0;j<i-1;j++){
      pot11[i].push_back(pot11[i-1][j]+pot11[i-1][j+1]);
    }
    pot11[i].push_back(1);
  }
  /*for(int i=0;i<52;i++){
    for(int j=0;j<pot11[i].size();j++){
      cout<<pot11[i][j]<<" ";
    }
    cout<<endl;
  }*/

  int t;
  cin>>t;

  getchar();
  int cont=0;
  while(t--){
    cont++;
    string linea;
    string pal,pal2;
    string pot;
    getline(cin,linea);
    int cond=0;
    bool primer=true;
    for(int i=1;i<linea.length();i++){
      if(cond==0){
        if(linea[i]=='+'){
          cond=1;
          continue;
        }
        pal+=linea[i];
      }
      else if(cond==1){
        if(linea[i]==')'){
          cond=2;
          continue;
        }
        pal2+=linea[i];
      }
      else{
        if(primer){
          primer=false;
          continue;
        }
        pot+=linea[i];
      }
    }
    int poten=0;
    if(pot.length()==2){
      poten+= (pot[0]-'0')*10+pot[1]-'0';
    }
    else{
      poten+=pot[0]-'0';
    }
    //cout<<pal<<" "<<pal2<<" "<<poten<<endl;
    int ind;
    printf("Case %d: ",cont);
    for(int i=0;i<=poten;i++){
      ind=poten-i;
      if(pot11[poten][i]>1){
        cout<<pot11[poten][i]<<'*';
      }
      if(ind>0){
        cout<<pal;
      }
      if(ind>1){
        cout<<'^'<<ind;
      }
      if(i>0){
      if(ind>0) cout<<'*';
        cout<<pal2;
      }
      if(i>1){
        cout<<'^'<<i;
      }
      if(i<poten) cout<<'+';
    }
    cout<<endl;

  }
  return 0;
}
