#include<iostream>
using namespace std;

int first_occurance(int arr[],int size,int key){
    int start =0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int ans =0;
    while(start<=end){
        if(key>arr[mid]){
            start = mid+1;
        }
        else if(key<arr[mid]){
            end = mid -1;
        }
        else{
            ans = mid;
            end = mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int last_occurance(int arr[],int size,int key){
    int start =0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int ans =0;
    while(start<=end){
        if(key>arr[mid]){
            start = mid+1;
        }
        else if(key<arr[mid]){
            end = mid -1;
        }
        else{
            ans = mid;
            start = mid+1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}
int main(){
    int arr[100];
    int size,key;
    cin>>size>>key;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<first_occurance(arr,size,key)<<" "<<last_occurance(arr,size,key);
}