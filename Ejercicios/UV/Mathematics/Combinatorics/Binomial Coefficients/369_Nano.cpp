#include<bits/stdc++.h>
using namespace std;
int main(){
  unsigned long long n,m;
  vector<int> ns;
  vector<int> ms;
  vector<unsigned long long> anss;
  while(cin>>n>>m){
  if(n==0 && m==0) break;


  int maxi,mini;
  if(n-m>m){
    maxi=n-m;
    mini=m;
  }
  else{
    maxi=m;
    mini=n-m;
  }
  vector<unsigned long long > xdd;
  for(int i=2;i<=mini;i++){
    xdd.push_back(i);
  }
  int ind=0;

  //cout<<xdd.size()<<endl;
  unsigned long long multi=1;
  for(int i=n;i>maxi;i--){
    multi*=i;
    if(ind<xdd.size()){


      while(multi%xdd[ind]==0){
        //cout<<xdd[ind]<<" "<<multi<<endl;
        multi/=xdd[ind];
        ind++;
        if(ind>=xdd.size()) break;
      }
    }
    //cout<<"sigo vivoooo\n";


    //printf("multi= %llu, ind= %d\n",multi,ind);
  }
  //cout<<"sali\n";

  ns.push_back(n);
  ms.push_back(m);
  anss.push_back(multi);

  }
  for(int i=0;i<ns.size();i++){
    printf("%d things taken %d at a time is %llu exactly.\n",ns[i],ms[i],anss[i]);
  }

  return 0;
}
