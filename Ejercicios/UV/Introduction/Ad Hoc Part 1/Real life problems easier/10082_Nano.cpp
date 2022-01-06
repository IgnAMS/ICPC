#include<bits/stdc++.h>
using namespace std;
char get(char a){
  char b;
  if(a=='W') b='Q';
  else if(a=='E') b='W';
  else if(a=='R') b='E';
  else if(a=='T') b='R';
  else if(a=='Y') b='T';
  else if(a=='U') b='Y';
  else if(a=='I') b='U';
  else if(a=='O') b='I';
  else if(a=='P') b='O';
  else if(a=='[') b='P';
  else if(a==']') b='[';
  else if(a=='\\') b=']';

  else if(a=='S') b='A';
  else if(a=='D') b='S';
  else if(a=='F') b='D';
  else if(a=='G') b='F';
  else if(a=='H') b='G';
  else if(a=='J') b='H';
  else if(a=='K') b='J';
  else if(a=='L') b='K';
  else if(a==';') b='L';
  else if(a=='\'') b=';';

  else if(a=='X') b='Z';
  else if(a=='C') b='X';
  else if(a=='V') b='C';
  else if(a=='B') b='V';
  else if(a=='N') b='B';
  else if(a=='M') b='N';
  else if(a==',') b='M';
  else if(a=='.') b=',';
  else if(a=='/') b='.';

  else if(a=='1') b='‘';
  else if(a=='2') b='1';
  else if(a=='3') b='2';
  else if(a=='4') b='3';
  else if(a=='5') b='4';
  else if(a=='6') b='5';
  else if(a=='7') b='6';
  else if(a=='8') b='7';
  else if(a=='9') b='8';
  else if(a=='0') b='9';
  else if(a=='-') b='0';
  else if(a=='=') b='-';

  else if(a==' ') b=' ';

  return b;
}



int main(){
  string linea;
  while(getline(cin,linea)){
    string linea2="";
    for(int i=0;i<linea.length();i++){
      linea2+=get(linea[i]);
    }
    cout<<linea2<<endl;
  }


  return 0;
}
