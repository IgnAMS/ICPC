#include<bits/stdc++.h>
using namespace std;

typedef pair<string,string> ss;
int main(){
  int n;
  cin>>n;
  int cont=0;
  set<ss> sets;
  string linea;
  while(n--){
    cin>>linea;
    string username="";
    string mailbox="";
    bool userdone=false;
    for(int i=0;i<linea.length();i++){
      if(linea[i]=='.' && !userdone){

      }
      else if(linea[i]=='+' && !userdone){
        userdone=true;
        while(linea[i+1]!='@') i++;

      }
      else if(userdone){
        mailbox+=linea[i];
      }
      else if(linea[i]=='@' && !userdone){
        userdone=true;
        mailbox+=linea[i];
      }
      else{
        username+=linea[i];
      }
    }
    sets.insert(ss(username,mailbox));
  }
  /*set<ss>::iterator it;
  for(it=sets.begin();it!=sets.end();it++){
    ss asd=*it;
    cout<<asd.first<<" "<<asd.second<<endl;
  }*/
  cout<<sets.size()<<endl;


  return 0;
}
