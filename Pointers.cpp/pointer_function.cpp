#include<iostream>
using namespace std;

int getSum(int *arr , int n){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum += i[arr];
    }
    return sum;
}

int main(){
    int arr[6] = {1,2,3,4,6,8};
    cout<<"Sum is :- "<<getSum(arr+3,3);
}