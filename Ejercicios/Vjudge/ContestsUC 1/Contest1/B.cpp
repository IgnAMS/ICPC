#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  while(getline(cin,linea)){
    vector<int> num;
    int aux=0;
    bool sign=true;

    for(int i=0;i<linea.length();i++){
      //cout<<i<<" "<<linea.length()<<endl;
      if(linea[i]=='-') sign=false;
      else if('0'<=linea[i] && linea[i]<='9'){
        aux*=10;
        aux+=linea[i]-'0';
        if(i==linea.length()-1){
          if(!sign) num.push_back(-1*aux);
          else num.push_back(aux);
          sign=true;
          aux=0;
        }
      }
      else if(linea[i]==' '){
        //cout<<"aux: "<<aux<<endl;
        if(!sign) num.push_back(-1*aux);
        else num.push_back(aux);
        sign=true;
        aux=0;
      }
    }
    //for(int i=0;i<num.size();i++) cout<<num[i]<<" "<<i<<endl;
    int ans;
    for(int i=0;i<num.size();i++){
      ans=num[i];
      int sum=0;
      for(int j=0;j<num.size();j++){
        if(j!=i) sum+=num[j];
      }
      //cout<<"ans: "<<ans<<" con i: "<<i<<" sum: "<<sum<<endl;
      if(sum==ans) break;
    }
    cout<<ans<<endl;
  }



  return 0;
}
