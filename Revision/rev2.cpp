#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<string> &board,int row,int col,int n){
    int nRows = row;
    int nCols = col;
    while(nRows>=0 && nCols>=0){
        if(board[nRows][nCols]=='Q'){
            return false;
        }
        nRows--,nCols--;
    }
    nRows = row;
    nCols = col;
    while(nCols>=0){
        if(board[nRows][nCols]=='Q'){
            return false;
        }
        nCols--;
    }
    nRows = row;
    nCols = col;
    while(nRows<n && nCols>=0){
        if(board[nRows][nCols]=='Q'){
            return false;
        }
        nRows++,nCols--;
    }
    return true;
}

void f(vector<vector<string>> &ans,vector<string> &board,int n,int col){
    if(col>=n){
        ans.push_back(board);
        return ;
    }
    for(int row=0;row<n;row++){
        if(isPossible(board,row,col,n)){
            board[row][col] = 'Q';
            f(ans,board,n,col+1);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> place_queen(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i] = s;
    }
    f(ans,board,n,0);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<string>> ans = place_queen(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<endl;
        }
        cout<<endl;
    }
}