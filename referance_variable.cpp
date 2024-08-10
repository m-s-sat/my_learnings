#include<iostream>
using namespace std;

void factorial(int &num){
    int factorial_2 = 1;
    for(int i=1;i<=num;i++){
        factorial_2 = factorial_2*i;
    }
    cout<<factorial_2;
}

int main(){
    int n;
    cout<<"Enter number :- ";
    cin>>n;
    factorial(n);
}