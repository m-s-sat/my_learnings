#include<iostream>
#include<vector>
using namespace std;

int f(vector<int> &arr,int low,int high){
    int pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=arr[pivot] && i<=high-1){
            i++;
        }
        while(arr[i]>arr[pivot] && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void quick_sort(vector<int> &arr,int low, int high){
    if(low<high){
        int partition = f(arr,low,high);
        quick_sort(arr,low,partition-1);
        quick_sort(arr,partition+1,high); 
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}