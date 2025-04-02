#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr,int l,int mid,int r){
    vector<int> temp;
    int index1 = l;
    int index2 = mid+1;
    while(index1<=mid && index2<=r){
        if(arr[index1]<arr[index2]){
            temp.push_back(arr[index1++]);
        }
        else{
            temp.push_back(arr[index2++]);
        }
    }
    while(index1<=mid){
        temp.push_back(arr[index1++]);
    }
    while(index2<=r){
        temp.push_back(arr[index2++]);
    }
    for(int i=l;i<=r;i++){
        arr[i] = temp[i-l];
    }
}

void sort(vector<int> &arr,int l,int r){
    if(l>=r){
        return ;
    }
    int mid = l+(r-l)/2;
    sort(arr,l,mid);
    sort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

void mergeSort(vector<int>&arr,int n){
    sort(arr,0,n-1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,n);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}