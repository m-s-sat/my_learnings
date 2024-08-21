#include<iostream>
using namespace std;

int main(){
    int arr[3];
    int min = INT16_MAX;
    for(int i=0;i<3;i++){
        cin>>arr[i];
    }
    for(int i=0;i<3;i++){
        if(min>arr[i]){
            min = arr[i];
        }
    }
    cout<<min;
}
