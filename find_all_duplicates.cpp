#include<iostream>
using namespace std;

void check_duplicates(int arr[],int size){
    int arr2[100]={0};
    // mapping number in arr2 like 0 -> 1, 1 -> 2 ans so on;
    for(int i=0;i<size;i++){
        arr2[arr[i]-1]++;
    }
    // checking two in which index number;
    for(int i=0;i<100;i++){
        if(arr2[i]==2){
            cout<<i+1<<" ";
        }
    }
}

int main(){
    int arr[100];
    int size;
    cout<<"Size of array :- ";
    cin>>size;
    cout<<"Value b/w [1,size] :- ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    check_duplicates(arr,size);
}
