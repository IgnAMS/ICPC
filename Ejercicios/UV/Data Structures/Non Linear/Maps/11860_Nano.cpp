#include<bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  vector<pair<int,int> > ans;

  while(t--){
    string linea;
    deque<string> total;
    map<string,int> mapa;

    while(getline(cin,linea)){
      if(linea=="END"){
        int p=0;
        int q=total.size()-1;
        set<string> asd;

        for(int i=0;i<(int)total.size();++i){
          for(int j=i+1;j<(int)total.size();++j){
            if(j-i>q-p) break;
            asd.clear();
            for(int h=i;h<=j;++h){
              asd.insert(total[h]);
            }
            if((int)asd.size() == (int)mapa.size()){
              if(j-i == q-p && i<p){
                q=j;
                p=i;
              }
              else if(j-i < q-p){
                q=j;
                p=i;
              }

            }
          }
          if(q-p == mapa.size()-1) break;
          mapa[total[i]]--;
          if(mapa[total[i]]==0) break;
        }

        mapa.clear();
        total.clear();
        ans.push_back(pair<int,int>(p+1,q+1));
        break;
      }
      string palabra;
      for(int i=0;i<(int)linea.length();++i){
        bool ins=false;
        if('a'<=linea[i] && linea[i]<='z'){
          palabra+=linea[i];
        }
        else{
          if(palabra!=""){
            if(mapa.count(palabra)) mapa[palabra]++;
            else{
              mapa.insert(pair<string,int> (palabra,1));
            }
            total.push_back(palabra);
            palabra="";
            ins=true;
          }
        }
        if(i==linea.length()-1 && palabra!="" && !ins){
          if(mapa.count(palabra)) mapa[palabra]++;
          else mapa.insert(pair<string,int>(palabra,1));
          total.push_back(palabra);
          palabra="";
        }
      }

    }

  }
  for(int i=0;i<(int)ans.size();++i){
    printf("Document %d: %d %d\n",i+1,ans[i].first,ans[i].second);
  }


  return 0;
}
