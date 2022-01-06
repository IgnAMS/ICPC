#include<bits/stdc++.h>
using namespace std;
int main(){
  double months, pay, total, n;
  while(cin>>months>>pay>>total>>n){
    vector<pair<double,double> > pct;
    double a,b;
    for(int i=0;i<n;i++){
      cin>>a>>b;
      pct.push_back(make_pair(a,(1.0-b)));
    }
    int ind=0;
    int in=0;
    double pagare=total;
    total+=pay;
    double mult=1;
    if(n>0){
      mult=pct[0].second;
    }
    cout<<total<<endl;
    total*=mult;
    cout<<total<<endl;
    for(int i=0;i<months;i++){
      if(total<=pagare) break;
      if(ind<pct.size()-1){
        if(i==pct[ind+1].first){
          ind++;
          mult=pct[ind].second;
        }
      cout<<"entre chaval"<<endl;
      total*=mult;
      pagare-=pay;
      cout<<total<<" "<<pagare<<endl;

    }
    cout<<total<<endl<<endl;
  }

  return 0;
}
