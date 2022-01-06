#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  string endlin = "****END_OF_TEXT****";
  string endin  = "****END_OF_INPUT****";
  map<string,int> mapa;
  map<string,int>::iterator it;
  vector<pair<pair<int,double>,int> > ans;
  int cont=0;
  set<char> car;
  car.insert(' ');
  car.insert(',');
  car.insert('.');
  car.insert(':');
  car.insert(';');
  car.insert('!');
  car.insert('?');
  car.insert('"');
  car.insert('(');
  car.insert(')');
  //car.insert('-');
  //car.insert('[');
  //car.insert(']');


  while(getline(cin,linea)){

    if(linea==endlin){
      double sum=0;
      for(it=mapa.begin();it!=mapa.end();it++){
        sum+=it->second*(log10(cont)-log10(it->second));
        //cout<<it->first<<endl;
      }
      sum/=cont;
      double xdd=sum/log10(cont)*1000;
      int meh=xdd;
      //cout<<xdd<<endl;
      if(meh%10 >=5) meh+=10;
      meh/=10;

      sum*=100;
      int asd=sum;
      if(asd%10>=5) asd+=10;
      asd/=10;
      sum=asd/10.0;


      //cout<<cont<<" "<<sum<<" "<<meh<<endl;
      ans.push_back(pair<pair<int,double>,int>(pair<int,double>(cont,sum),meh));
      mapa.clear();
      cont=0;
      continue;
    }
    else if(linea==endin) break;
    string pal="";
    for(int i=0;i<linea.length();i++){
      bool ins=false;
      //if(('a'<=linea[i] && linea[i]<='z') || ('A'<=linea[i] && linea[i]<='Z') || ('0'<=linea[i] && linea[i]<='9')){
      if(!car.count(linea[i])){
        if('A'<=linea[i] && linea[i]<='Z'){
          linea[i]= linea[i]-'A'+'a';
        }
        pal+=linea[i];
      }
      else{
        if(pal!=""){
          if(!mapa.count(pal))
            mapa.insert(pair<string,int> (pal,1));
          else
            mapa[pal]++;
          pal="";
          cont++;
          ins=true;
        }
      }
      if(i==linea.length()-1 && !ins){
        if(pal!=""){
          if(!mapa.count(pal))
            mapa.insert(pair<string,int> (pal,1));
          else
            mapa[pal]++;
          pal="";
          cont++;
        }
      }
    }

  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i].first.first<<" ";
    cout<<setprecision(1)<<fixed<<ans[i].first.second;
    cout<<" "<<ans[i].second<<endl;
  }

  return 0;
}
