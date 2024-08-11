#include<iostream>
using namespace std;

inline int getMax(int& a,int &b){
    return (a>b ? a:b);
}

int main(){
    int a=2;
    int b=3;
    cout<<getMax(a,b)<<endl;
    a+=2;
    b+=1;
    cout<<getMax(a,b)<<endl;

}