#include<iostream>
using namespace std;

int main(){
    int num;
    cin>>num;

    // adress operator -> &;
    cout<<"Address of num :- "<<&num<<endl;

    int *p = &num;

    cout<<"Address of num :- "<<p<<endl;
    cout<<"Value of num :- "<<*p<<endl;

    double num2 = 4.20;
    double *ptr = &num2;

    cout<<"Address of ptr :- "<<ptr<<endl;
    cout<<"Value of ptr :- "<<*ptr<<endl;

    cout<<"size of int :- "<<sizeof(num)<<endl;
    cout<<"Size of pointer ptr :- "<<sizeof(ptr)<<endl;
    cout<<"Size of pointer p :- "<<sizeof(p)<<endl;
}