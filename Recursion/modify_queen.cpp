#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<string>&ans,int row,int col,int n){
    int nRows = row;
    int nCols = col;
    while(nRows>=0 && nCols>=0){
        if(ans[nRows][nCols]=='Q'){
            return false;
        }
        nRows--,nCols--;
    }
    nRows = row;
    nCols = col;
    while(nCols>=0){
        if(ans[nRows][nCols]=='Q'){
            return false;
        }
        nCols--;
    }
    nRows = row;
    nCols = col;
    while(nRows<n && nCols>=0){
        if(ans[nRows][nCols]=='Q'){
            return false;
        }
        nRows++,nCols--;
    }
    return true;
}

bool place_queen(vector<string> &ans,int n,int col){
    if(col>=n){
        return true;
    }
    for(int row=0;row<n;row++){
        if(isPossible(ans,row,col,n)){
            ans[row][col] = 'Q';
            if(place_queen(ans,n,col+1)==true){
                return true;
            }
            else{
                ans[row][col] = '.';
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<string> ans(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        ans[i] = s;
    }
    place_queen(ans,n,0);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<endl;
    }
}