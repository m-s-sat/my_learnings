#include<iostream>
using namespace std;

bool isSorted(int *arr,int size){
    if(size==0||size==1){
        return true;
    }
    if(arr[0]>arr[1]){
        return false;
    }
    else{
        bool sorted = isSorted(arr+1,size-1);
        return sorted;
    }
}

int main(){
    int arr[100];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    if(isSorted(arr,size)){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Array is not sorted"<<endl;
    }
}