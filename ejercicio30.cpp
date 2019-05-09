#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
  double L=1.0;
  double delta_x = 0.01;
  double delta_t = 0.01;
  double t_max = 2.0;
  double t;
  double epsilon=1.0;
  double betha=delta_t*epsilon/delta_x;

  int n_side = L/(delta_x) + 1;
    
  double onda_presente[n_side];
  double onda_futuro[n_side];
    
  ofstream outfile;
  int i;
  int j;

  for(i=0;i<n_side;i++){
    onda_presente[i] = (sin(4*M_PI * i /n_side))/20;
  }
  
  onda_presente[0]=0.0;
  onda_presente[n_side-1]=0.0;

  outfile.open("onda.dat");

  while(t < t_max){
    for(i=0;i<n_side;i++){
        onda_futuro[i] = onda_presente[i] - (betha/4)*(pow(onda_presente[i+1],2) - pow(onda_presente[i-1],2)) + (pow(betha,2)/8)*((onda_presente[i+1]+onda_presente[i])*(pow(onda_presente[i+1],2)-pow(onda_presente[i],2))-(onda_presente[i]+onda_presente[i-1])*(pow(onda_presente[i],2)-pow(onda_presente[i-1],2)));
        
      outfile << onda_futuro[i] << " ";
    }
    outfile << "\n";
    
    for(i=1;i<n_side-1;i++){
      onda_presente[i] = onda_futuro[i];
    }
    t = t + delta_t;
  }
  outfile.close();

  return 0;
}
