#include<iostream>
#include<string>
#include<fstream>
#include <stdlib.h>
using namespace std;

int encuentra_banana(string linea){
  int contador=0;int banana=0;
  for (int i=0; i<linea.length();i++){
    linea[i]=tolower(linea[i]);
  }
  cout<<linea;
  while(1){
    int numerobanana=linea.find("banana",contador);
    contador=numerobanana+1;
    if(numerobanana!=-1){
      banana++;
    }else{
      break;
    }
  }
  return banana;
}

int contadorbanana(const char *filename){
  int counter=0;
  string linea;
  ifstream file(filename);
  if (file.is_open()){
    while(getline(file, linea)){
      counter=counter+encuentra_banana(linea);
    }
  }
}
int main(){
  string nombre= "banana.txt";
  int counter;
  counter= contadorbanana(nombre.c_str());
  cout<<"Hay un total de "<<counter<<" bananas en tu texto"<<endl;
  return 0;
}
