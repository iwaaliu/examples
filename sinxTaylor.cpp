#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;

float sinx(float x,int n)
{
  // int i;
   float sin;
   if(n==0) {return 0.0;}
   else{
      sin=0.;
     for (int i=1;i<=n;i=i+2)
       {
         float fac=(i-1.0)*i;
         if(i==1) fac=1.;
         sin=sin+pow(-1,i/2)*pow(x,i)/fac;}
   }
   return sin;
}

int main()
{
  int n;
  float x, y;
  cout<<"Please input your x (x is small and close to 0), and n (Taylor expansion order)"<<endl;
  cin>>x>>n;
  cout<<"The resulttaylor expansion of sin(x) for  "<<n<<"order"<<"at"<<x<<":"<<endl;
  y=sinx(x,n);
  cout<<"sin(x)="<<y<<endl;
  return 0;
}
