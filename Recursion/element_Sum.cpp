#include<iostream>
using namespace std;

int sum(int *arr,int size){
    if(size<0){
        return 0;
    }
    return arr[size-1]+sum(arr,size-1);
}

int main(){
    int size;
    int arr[100];
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int ans = sum(arr,size);
    cout<<"Sum is : "<<ans;
}