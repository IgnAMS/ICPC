#include<bits/stdc++.h>
using namespace std;
int main(){
  string linea;
  vector<int> ans;
  int cont=0;
  string pal="";
  int a=0,b=0,c=0,d=0,e=0;
  map<string,int> conts;

  while(true){
    cont++;
    e++;
    if(e>26){
      d++;
      if(d>25){
        c++;
        if(c>24){
          b++;
          if(b>23){
            a++;
            if(a>22) break;
            b=a+1;
          }
          c=b+1;
        }
        d=c+1;
      }
      e=d+1;
    }
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<endl;
    pal="";
    if(a>0) pal+=a+'a'-1;
    if(b>0) pal+=b+'a'-1;
    if(c>0) pal+=c+'a'-1;
    if(d>0) pal+=d+'a'-1;
    if(e>0) pal+=e+'a'-1;
    //cout<<pal<<" "<<cont<<endl;
    conts.insert(pair<string,int>(pal,cont));
  }


  while(cin>>linea){
    //if(linea=="meh") break;
    int cont=0;
    if(!conts.count(linea)) cont=0;
    else{
      cont=conts[linea];
    }
    //cout<<cont<<endl;
    ans.push_back(cont);
  }
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<endl;
  }

  return 0;
}
