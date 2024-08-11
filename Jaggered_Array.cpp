#include<iostream>
using namespace std;

int main(){
    int row,col;
    int arr_2[100];
    cout<<"Enter row :- ";
    cin>>row;
    int **arr_1 = new int*[row];
    for(int i=0;i<row;i++){
        cout<<"Enter cols :- ";
        cin>>col;
        arr_2[i]=col;
        arr_1[i] = new int[col];
        for(int j=0;j<col;j++){
            cin>>arr_1[i][j];
        }
    }
    cout<<"Print :- "<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<arr_2[j];j++){
            cout<<arr_1[i][j]<<" ";
        }
        cout<<endl;
    }
}