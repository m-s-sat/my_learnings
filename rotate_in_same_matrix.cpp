#include<iostream>
using namespace std;

void rotate_array(int arr[][4],int nRows,int nCols){
    int row=1;
    int col=1;
    while(row<nRows && col<nCols){
        for(int i=0,j=0;i<row,j<col;i++,j++){
            swap(arr[row][i],arr[j][col]);
        }
        row++;
        col++;
    }
    for(int row=0;row<nRows;row++){
        int start = 0;
        int end = nRows-1;
        while(start<=end){
            swap(arr[row][start],arr[row][end]);
            start++;
            end--;
        }
    }
}

void print_array(int arr[][4],int nRows,int nCols){
    for(int row=0;row<nRows;row++){
        for(int col=0;col<nCols;col++){
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
    cout<<"Printing before rotate :- "<<endl;
    print_array(arr,4,4);
    rotate_array(arr,4,4);
    cout<<"Printing after rotate :- "<<endl;
    print_array(arr,4,4);

}