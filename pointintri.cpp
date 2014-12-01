#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Point { //point class defines an arbitrary point.
public:
  float x,y;
  float xval,yval;
  void set_values (float,float);
  float dist;

};

  void Point::set_values (float a, float b){
    x=a;xval=x;
    y=b;yval=y;
  }

class Points { // defines two points properties, includes distance and others
  Point p1,p2;
public:
  void set_ps(Point,Point);
  float dist (void) {float d=(p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);return sqrt(d);}
};

void Points::set_ps(Point p_1,Point p_2){
  p1=p_1;p2=p_2;
}


class Tri {//defines a triangle with three points
  Point p1,p2,p3;
  float a,b,c;
  public:
  void set_tri(Point, Point, Point);
  float area (void) {float s=.5*(a+b+c);float Area=sqrt(s*(s-a)*(s-b)*(s-c)); return Area;};
  // area=1.0;
};

void Tri::set_tri(Point p1,Point p2,Point p3){
  Points ps1,ps2,ps3;
  ps1.set_ps(p1,p2);
  a=ps1.dist();
  ps2.set_ps(p3,p2);
  b=ps2.dist();  
  ps3.set_ps(p1,p3);
  c=ps3.dist();
}

    int main () {
      Point a, b, c,d;
      float tol=.1e-9;
      cout<<"Point 1:\nbefore set up initial: "<<a.xval<<" "<<a.yval<<endl;
      a.set_values(-1.,-1.);
      b.set_values(1.,-1.);
      c.set_values(-1.,1.);
      cout<<"after set up initial: "<<a.xval<<" "<<a.yval<<endl;
      Tri t0,t1,t2,t3;
      t0.set_tri(a,b,c);
      
      cout<<t0.area()<<endl;
      float x,y;
      cin>>x>>y;
       cout<<x<<";"<<y<<endl;
       d.set_values(x,y);
      t1.set_tri(a,b,d);
      t2.set_tri(a,c,d);
      t3.set_tri(b,c,d);

      float Atotal=t1.area()+t2.area()+t3.area();
      float atri=t0.area();

      if(fabs(Atotal-atri)>tol) 
	{cout<<"Point is outside the triangle."<<endl;}
      else
	{
	  if(t1.area()<tol or t2.area()<tol or t3.area()<tol)
	    {cout<< "Point is on the edge of the triangle."<<endl;}
	  else
	    {cout<<"Point is inside the triangle."<<endl;}
	}
 
      return 0;
    }
