#include<iostream>
using namespace std;

bool binary_key_search(int *arr,int s,int e,int k){
    if(s>e){
        return false;
    }
    int mid = s+(e-s)/2;
    if(k==arr[mid]){
        return true;
    }
    else if(k<arr[mid]){
        return binary_key_search(arr,s,mid-1,k);
    }
    else{
        return binary_key_search(arr,mid+1,e,k);
    }
    
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(binary_key_search(arr,0,n-1,k)){
        cout<<"Key is found"<<endl;
    }
    else{
        cout<<"Key is not found"<<endl;
    }
}