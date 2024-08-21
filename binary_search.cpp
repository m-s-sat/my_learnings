#include<iostream>
using namespace std;

int binary_search(int arr[],int size,int key){
    int start =0;
    int end = size-1;
    int mid = (start+end)/2;
    while(start<=end){
        if(arr[end]>key){
            end = mid-1;
        }
        else if(arr[start]<key){
            start = mid +1;
        }
        else{
            return mid;
        }
        mid = (start+end)/2;
    }
    return -1;
}

int main(){
    int arr[100];
    int n,key;
    cin>>n>>key;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<binary_search(arr,n,key);
    
}