#include<iostream>
using namespace std;

void rotated_array(int arr[][3],int nRows,int nCols){
    for(int col=0;col<nCols;col++){
        for(int row=nRows-1;row>=0;row--){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[3][3];
    cout<<"Taking Inputs :- ";
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cin>>arr[row][col];
        }
    }
    cout<<"Printing array :- "<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<"Printing rotated array :- "<<endl;
    rotated_array(arr,3,3);
}