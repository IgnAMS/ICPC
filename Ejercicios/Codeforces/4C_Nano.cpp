#include<bits/stdc++.h>
using namespace std;
int main(){
  int a;
  cin>>a;
  map<string,int> asd;
  map<string,vector<string> > users;
  string linea;

  for(int i=0;i<a;i++){
    cin>>linea;
    if(!asd.count(linea)){
      users.insert(pair<string, vector<string> > (linea,vector<string>()) );
    }
    else{
      users[linea]
    }
  }





  return 0;
}
