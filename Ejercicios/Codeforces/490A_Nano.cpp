#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  deque<int> math;
  deque<int> prog;
  deque<int> ed;
  cin>>n;
  int h;
  for(int i=0;i<n;i++){
    cin>>h;
    if(h==1) math.push_back(i+1);
    if(h==2) prog.push_back(i+1);
    if(h==3) ed.push_back(i+1);
  }
  //math,prog,ed
  int asd=min(min(math.size(),prog.size()),ed.size());
  cout<<asd<<endl;
  while(!math.empty() && !prog.empty() && !ed.empty()){
    cout<<math.front()<<" "<<prog.front()<<" "<<ed.front()<<endl;
    math.pop_front();
    prog.pop_front();
    ed.pop_front();
  }



  return 0;
}
