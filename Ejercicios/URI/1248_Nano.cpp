#include<bits/stdc++.h>
using namespace std;



int main() {
  int n;
  cin>>n;
  getchar();
  while(n--){
    string dieta, desayuno, almuerzo;

    vector<int> algo(26,0);
    bool state=true;

    //cin>>dieta>>desayuno>>almuerzo;
    getline(cin,dieta);
    getline(cin,desayuno);
    getline(cin,almuerzo);

    char a='A';
    int N= a;
    //cout<<N<<"\t";
    //printf("%s dieta\n%s\n%s\n\n", dieta.c_str(),desayuno.c_str(),almuerzo.c_str());

    for(int i=0;i<dieta.length();i++){
      algo[dieta[i]-65]++;
      if(algo[dieta[i]-65]>1){
        algo[dieta[i]-65]=1;
      }
    }
    for(int i=0;i<desayuno.length();i++){
      algo[desayuno[i]-65]--;
      if(algo[desayuno[i]-65]<0){
        state=false;
        break;
      }
    }
    for(int i=0;i<almuerzo.length();i++){
      algo[almuerzo[i]-65]--;
      if(algo[almuerzo[i]-65]<0){
        state=false;
        break;
      }
    }
    for(int i=0;i<algo.size();i++){
      //cout<<algo[i]<<"\t";
    }
    if(!state){
      cout<<"CHEATER";
    }
    else{
      for(int i=0;i<algo.size();i++){
        if(algo[i]>0){
          switch(i){
          case 0: cout<<"A";break;
          case 1: cout<<"B";break;
          case 2: cout<<"C";break;
          case 3: cout<<"D";break;
          case 4: cout<<"E";break;
          case 5: cout<<"F";break;
          case 6: cout<<"G";break;
          case 7: cout<<"H";break;
          case 8: cout<<"I";break;
          case 9: cout<<"J";break;
          case 10: cout<<"K";break;
          case 11: cout<<"L";break;
          case 12: cout<<"M";break;
          case 13: cout<<"N";break;
          case 14: cout<<"O";break;
          case 15: cout<<"P";break;
          case 16: cout<<"Q";break;
          case 17: cout<<"R";break;
          case 18: cout<<"S";break;
          case 19: cout<<"T";break;
          case 20: cout<<"U";break;
          case 21: cout<<"V";break;
          case 22: cout<<"W";break;
          case 23: cout<<"X";break;
          case 24: cout<<"Y";break;
          case 25: cout<<"Z";break;
        }
        }

      }
    }
    cout<<endl;


  }

	return 0;
}
