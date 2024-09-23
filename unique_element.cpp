#include<iostream>
using namespace std;

int unique_element(int arr[],int size){
    int value=0;
    for(int i=0;i<size;i++){
        value = arr[i]^value; 
    }
    return value;
}

int main(){
    int arr[1000];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int ans = unique_element(arr,size);
    cout<<ans;
}