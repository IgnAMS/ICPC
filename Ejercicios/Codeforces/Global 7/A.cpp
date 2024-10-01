#include<bits/stdc++.h>
using namespace std;

void printvect(vector<int> a){
  for(int i=0;i<a.size();i++) cout<<a[i];
  cout<<endl;
  return;
}

bool check(vector<int> a){
  set<int> div;
  int suma=0;
  for(int i=0;i<a.size();i++){
    div.insert(a[i]);
    suma+=a[i];
  }
  set<int>::iterator it;
  bool state=true;
  int segundo;
  int tercer;
  //printvect(a);
  int siz=a.size();
  int primer=a[a.size()-1];
  if(a.size()>1) segundo=a[a.size()-2]*10+primer;
  else segundo=primer;
  if(a.size()>2) tercer=tercer=a[a.size()-3]*100+segundo;
  else tercer=segundo;
  if(div.count(2) && primer%2==0) state=false;
  if(div.count(3) && suma%3==0) state=false;
  if(div.count(4) && segundo%4==0) state=false;
  if(div.count(5) && primer%5==0) state=false;
  if(div.count(6) && primer%2==0) state=false;
  if(div.count(8) && tercer%8==0) state=false;
  if(div.count(9) && suma%3==0) state=false;
  //cout<<"state: "<<state<<endl;
  //cout<<"primer: "<<primer<<endl;
  if(!state) return state;
  if(div.count(7)){
    state=false;
  }
  return state;
}
bool cycle(vector<int> a){
  bool state=true;
  for(int i=0;i<a.size();i++) if(a[i]!=9) state=false;
  return state;
}


int main(){
  int t;
  cin>>t;
  vector<vector<int> > ans;
  while(t--){
    int n;
    cin>>n;
    vector<int> puchis(1,-1);
    bool inserta2=false;
    vector<int> num(n,2);
    int ind=0;
    while(!cycle(num)){
      //cout<<"deberia imprimir..."<<endl;
      if(num.size()==1){
        ans.push_back(puchis);
        inserta2=true;
        break;
      }
      num[n-1]++;
      if(check(num)){
        ans.push_back(num);
        inserta2=true;
        break;
      }
      //printvect(num);
      bool goon=true;
      if(cycle(num)) break;
      for(int i=n-1;i>=1&& goon;i--){
        if(num[i]==9){
          //cout<<"ind: "<<ind<<", i: "<<i<<", num[ind]: "<<num[ind]<<" num[i]: "<<num[i]<<endl;
          if(i==ind+1 && num[ind]==8){
            num[ind]++;
            num[i]=2;
            ind++;
            break;
          }
          num[i]=2;
          num[i-1]++;
        }
        else goon=false;
      }
    }
    if(!inserta2) ans.push_back(puchis);

  }
  for(int i=0;i<ans.size();i++){
    for(int j=0;j<ans[i].size();j++){
      cout<<ans[i][j];
    }
    cout<<endl;
  }

  return 0;
}
