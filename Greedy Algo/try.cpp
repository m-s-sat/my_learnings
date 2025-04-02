#include<iostream>
using namespace std;

void f(int n){
    if(n>2){
        f(n-1);
        f(n-2);
        f(n-3);
    }
    cout<<n<<" ";
    return ;
}

int main(){
    f(5);
}