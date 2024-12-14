#include<iostream>
using namespace std;

int pivot_element(int *arr,int s,int e){
    int mid = s+(e-s)/2;
    if(s==e){
        return mid;
    }
    if(arr[mid]>arr[0]){
        return pivot_element(arr,mid+1,e);
    }
    else{
        return pivot_element(arr,s,mid);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<pivot_element(arr,0,n-1)<<endl;
}