#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[100];
    int size;
    vector<int> element;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int s=0;
    int e=1;
    while(e<size){
        if(arr[s]>arr[e]){
            element.push_back(arr[e]);
            s++,e++;
        }
        else{
            
        }
    }
}