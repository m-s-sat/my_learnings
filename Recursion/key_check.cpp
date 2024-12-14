#include<iostream>
using namespace std;

bool key_check(int *arr,int n,int k){
    if(n==0){
        return false;
    }
    if(arr[0]==k){
        return true;
    }
    return key_check(arr+1,n-1,k);
}

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(key_check(arr,n,k)){
        cout<<"Key is found"<<endl;
    }
    else{
        cout<<"Key is not found"<<endl;
    }
}