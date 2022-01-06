#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  vector<map<string,set<string> > > ans;
  while(t--){
    int n;
    cin>>n;
    map<string,set<string> > mapa;
    while(n--){
      string pizza;
      cin>>pizza;
      int mi;
      cin>>mi;
      vector<string> a;
      string ingredent;
      for(int i=0;i<mi;i++){
        cin>>ingredent;
        a.push_back(ingredent);
      }
      vector<string> b;
      cin>>mi;
      for(int i=0;i<mi;i++){
        cin>>ingredent;
        b.push_back(ingredent);
      }
      for(int i=0;i<mi;i++){
        if(!mapa.count(a[i])){
          mapa.insert(pair<string,set<string> >(a[i],set<string>()));
        }
        mapa[a[i]].insert(b[i]);
      }
    }
    ans.push_back(mapa);
  }
  map<string,set<string> >::iterator it;
  set<string>::iterator it2;
  for(int i=0;i<ans.size();i++){
    for(it=ans[i].begin();it!=ans[i].end();++it){
      //cout<<it->first<<endl;
      for(it2=it->second.begin();it2!=it->second.end();++it2){
        //printf("(%s, %s)\n",it->first,*it2);
        cout<<"("<<it->first<<", "<<*it2<<")\n";
      }
    }
    if(i<ans.size()-1) cout<<endl;
  }

  return 0;
}
