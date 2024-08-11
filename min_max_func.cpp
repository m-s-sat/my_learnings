#include<iostream>
#include<vector>
using namespace std;

void minmaxfunc(int *arr, int size){
    long maxi = INT32_MIN;
    long mini = INT32_MAX;
    long sum_max = 0;
    long sum_min = 0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    for(int i=1;i<size;i++){
        sum_max += arr[i];
    }
    for(int i=0;i<(size-1);i++){
        sum_min += arr[i];
    }
    cout<<sum_max<<" "<<sum_min;
}

int main(){
    int size;
    cout<<"Size of an array :- ";
    cin>>size;
    int * arr = new int[size];
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    minmaxfunc(arr,size);

}