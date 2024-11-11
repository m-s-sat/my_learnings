#include<iostream>
using namespace std;

int target(int *arr,int n,int k){
    if(n<0){
        return -1;
    }
    if(arr[0]==k){
        return k;
    }
    else{
        target(arr+1,n-1,k);
    }
}

int main(){
    int arr[100];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<target(arr,n,k)<<endl;
}
