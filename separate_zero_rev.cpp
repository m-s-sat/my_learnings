#include<iostream>
using namespace std;

void separet_zero(int arr[],int size){
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            for(int j=i+1;j<size;j++){
                if(arr[j]!=0){
                    swap(arr[i],arr[j]);
                    break;
                }
            }      
        }
    }
}

void print_array(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[100];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    separet_zero(arr,size);
    print_array(arr,size);
}