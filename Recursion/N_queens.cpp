#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string> &boards,int col,int row,int n){
    int nRows = row;
    int nCols = col;
    while(nRows>=0 && nCols>=0){
        if(boards[nRows][nCols]=='Q'){
            return false;
        }
        nRows--,nCols--;
    }
    nRows = row;
    nCols = col;
    while(nCols>=0){
        if(boards[nRows][nCols]=='Q'){
            return false;
        }
        nCols--;
    }
    nRows = row;
    nCols = col;
    while(nCols>=0 && nRows<n){
        if(boards[nRows][nCols]=='Q'){
            return false;
        }
        nCols--,nRows++;
    }
    return true;
}

void queen(vector<string> &boards,vector<vector<string>>&ans ,int col,int n){
    if(col>=n){
        ans.push_back(boards);
        return ;
    }
    for(int row = 0;row<n;row++){
        if(isSafe(boards,col,row,n)){
            boards[row][col] = 'Q';
            queen(boards,ans,col+1,n);
            boards[row][col] = '.';
        }
    }
}

vector<vector<string>> place_queens(int n){
    vector<vector<string>> ans;
    vector<string> boards(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        boards[i] = s;
    }
    queen(boards,ans,0,n);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<string>> ans = place_queens(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
}