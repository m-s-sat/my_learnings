#include<iostream>
using namespace std;

int peak_mountain_array(int *arr,int s,int e){
    int mid = s+(e-s)/2;
    if(s==e){
        return mid;
    }
    if(arr[mid]<arr[mid+1]){
        return peak_mountain_array(arr, mid+1,e);
    }
    else{
        return peak_mountain_array(arr,s,mid);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<peak_mountain_array(arr,0,n-1)<<endl;
}