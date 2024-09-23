#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int row =1;
    while(row<=n){
        int col = 1;
        for(int i=1;i<=n-row;i++){
            cout<<" ";
        }
        while(col<=row){
            cout<<"*";
            col++;
        }
        int i=1;
        while(i<col-1){
            cout<<"*";
            i++;
        }
        row++;
        cout<<endl; 
    }
    row=1;
    while(row<=n){
        int col=1;
        for(int i=1;i<=row;i++){
            cout<<" ";
        }
        while(col<=(2*(n-row)-1)){
            cout<<"*";
            col++;
        }
        cout<<endl;
        row++;
    }
}