#include<iostream>
using namespace std;

int binary_search(int *arr,int s,int e,int k){
    if(s>e){
        return -1;
    }
    int mid = s+(e-s)/2;
    if(arr[mid]<k){
        return binary_search(arr,mid+1,e,k);
    }
    else if(arr[mid]>k){
        return binary_search(arr,s,mid-1,k);
    }
    else{
        return mid;
    }
}

int main(){
    int arr[100];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Index is : "<<binary_search(arr,0,n-1,k);
}