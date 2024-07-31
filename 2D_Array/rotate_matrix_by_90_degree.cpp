#include<iostream>
using namespace std;

void rotate_matrix(int arr[][4],int nRows,int nCols){
    for(int col=0;col<nCols;col++){
        for(int row=nRows-1;row>=0;row--){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int arr[4][4];
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            cin>>arr[row][col];
        }
    }
    cout<<"Printing before rotation :- "<<endl;
    for(int row=0;row<4;row++){
        for(int col=0;col<4;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<"Printing after rotation :- "<<endl;
    rotate_matrix(arr,4,4);
}