#include<iostream>
using namespace std;

void rotatate_arr(int *arr,int size){
    int start = 0;
    int end = size-1;
    while(start<=end){
        swap(*(arr+start),*(arr+end));
        start++,end--;
    }
}
void printArray(int *arr,int size){
    for(int i=0;i<size;i++){
        cout<<*(arr+i);
    }
}
int main(){
    int size;
    cout<<"Size of arr you want :- ";
    int *arr = new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Before rotate :- ";
    printArray(arr,size);
    rotatate_arr(arr,size);
    cout<<"After rotate :- ";
    printArray(arr,size);
}