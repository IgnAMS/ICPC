#include<bits/stdc++.h>
using namespace std;

int main(){
  string linea;
  cin>>linea;
  vector<int> num;
  for(int i=0;i<linea.length();i++){
    if(linea[i]=='.'){
      num.push_back(0);
    }
    else if(linea[i]=='-' && linea[i+1]=='-'){
      i++;
      num.push_back(2);
    }
    else if(linea[i]=='-' && linea[i+1]=='.'){
      i++;
      num.push_back(1);
    }
  }
  for(int i=0;i<num.size();i++){
    cout<<num[i];
  }
  cout<<endl;

  return 0;
}
