#include<iostream>
using namespace std;

void bubble_sort(int arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=0;j<n-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void printArray(int arr[],int m){
    for(int i=0;i<m;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[8] = {5,1,3,6,4,2,9,8};
    bubble_sort(arr,8);
    printArray(arr,8);
}