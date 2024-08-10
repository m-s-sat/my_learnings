#include<iostream>
using namespace std;

int main(){
    int i=10;
    int *p=&i;
    // i++;
    // (*p)++;
    // cout<<*p;
    cout<<"before upgradtion :- "<<p<<endl;
    p=p+1;
    cout<<"After upgradation :- "<<p<<endl;
    
}