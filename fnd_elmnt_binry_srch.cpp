#include<iostream>
using namespace std;

int pivot_element(int arr[],int n){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;
    while(s<e){
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return e;
}

int binary_search(int arr[],int n,int k,int s,int e){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(arr[mid]==k){
            return mid;
        }
        else if(arr[mid]<k){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int main(){
    int arr[100];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int index = pivot_element(arr,n);
    if(k>=arr[index]&&k<=arr[n-1]){
        cout<<binary_search(arr,n-1-index,k,index,n-1);
    }
    else{
        cout<<binary_search(arr,index,k,0,index-1);
    }
}