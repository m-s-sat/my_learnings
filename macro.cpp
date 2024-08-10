#include<iostream>
#include<math.h>
using namespace std;

#define PI 3.14
#define AREA(l,b) (l*b)
#define AREA_1(r,h) (PI*pow(r,2)*h) 

int main(){
    int r,l1,b1,r1,h;
    cin>>r>>l1>>b1>>r1>>h;
    cout<<"area of circle :- "<<PI*pow(r,2)<<" and area of square :- "<<AREA(l1,b1)<<" and area of cylinder :- "<<AREA_1(r1,h);
}