#include<iostream>
using namespace std;

void reverse_array(int arr[],int size){
    int start = 0;
    int end = size - 1;
    while(start<end){
        swap(arr[start],arr[end]);
        start ++ , end--;
    }
}

void print_array(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

void take_input(int arr[],int size){
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
}

int main(){
    int arr1[1000];
    int length;
    cout<<"Length of an array :- ";
    cin>>length;
    take_input(arr1,length);
    reverse_array(arr1,length);
    print_array(arr1,length);
}