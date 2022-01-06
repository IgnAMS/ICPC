#include<bits/stdc++.h>
using namespace std;
vector<set<int> > asd(60003,set<int>());
std::set<int>::iterator it;

void divs(int n){
  if(asd[n].size()==0){
    asd[n].insert(1);
    for(int j=2;j<=sqrt(n);j++){
      if(n%j==0){
        asd[n].insert(j);
        asd[n].insert(n/j);
      }
    }
  }
  return;
}



int main(){
  int a;
  cout<<"PERFECTION OUTPUT\n";
  while(cin>>a){
    if(a==0) break;

    divs(a);
    unsigned long long sum=0;
    for(it=asd[a].begin();it!=asd[a].end() && a!=1;++it){
      sum+=*it;
    }

    int asd= log10(a)+1;
    int spaces=5-asd;
    for(int i=0;i<spaces;i++)cout<<" ";
    cout<<a<<"  ";
    //cout<<sum<<"  ";
    if(sum==a) cout<<"PERFECT";
    else if(sum<a) cout<<"DEFICIENT";
    else if(sum>a) cout<<"ABUNDANT";
    cout<<endl;
  }
  cout<<"END OF OUTPUT\n";

  return 0;
}
