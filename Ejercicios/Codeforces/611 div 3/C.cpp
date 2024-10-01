#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> cabros(n,0);
  int h;
  int imp=0;
  int first;
  bool meh=true;
  vector<bool> asd(n,false);
  for(int i=0;i<n;i++){
    cin>>h;
    if(h==0 && meh){
      first=i;
      meh=false;
    }
    if(h==0) imp++;
    cabros[i]=h;
    if(h>0){
      asd[h-1]=true;
    }
  }
  //for(int i=0;i<n;i++) cout<<asd[i]<<" ";
  //cout<<endl;
  if(imp%2!=0){
    for(int i=0;i<n;i++){
      if(!asd[i] && i!=first){
        asd[i]=true;
        cabros[first]=i+1;
        break;
      }
    }
  }
  /*
  for(int i=0;i<n;i++) cout<<cabros[i]<<" ";
  cout<<endl;
  for(int i=0;i<n;i++) cout<<asd[i]<<" ";
  cout<<endl;*/
  deque<int> notvist;
  for(int i=0;i<n;i++){
    if(!asd[i]){
      notvist.push_back(i+1);
    }
  }
  for(int i=n-1;i>=0;i--){
    if(cabros[i]==0){
      if(notvist.front()==i+1){
        int aux=notvist.front();
        notvist.pop_front();
        cabros[i]=notvist.front();
        notvist.pop_front();
        notvist.push_front(aux);
        continue;
      }
      cabros[i]=notvist.front();
      asd[notvist.front()-1]=true;
      notvist.pop_front();

    }
  }
  //for(int i=0;i<n;i++) cout<<asd[i]<<" ";
  //cout<<endl;
  for(int i=0;i<n;i++) cout<<cabros[i]<<" ";
  cout<<endl;
  //for(int i=0;i<n;i++) cout<<asd[i]<<" ";
  //cout<<endl;


  return 0;
}
