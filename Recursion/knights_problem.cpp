#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<int>>&grid,int row,int col,int temp){
    int n = grid.size();
    if(row>1){
        if(col-1>=0 && grid[row-2][col-1]==temp-1){
            return true;
        }
        if(col+1<n && grid[row-2][col+1]==temp-1){
            return true;
        }
    }
    if(row<n-2){
        if(col-1>=0 && grid[row+2][col-1]==temp-1){
            return true;
        }
        if(col+1<n && grid[row+2][col+1]==temp-1){
            return true;
        }
    }
    if(col>1){
        if(row+1<n && grid[row+1][col-2]==temp-1){
            return true;
        }
        if(row-1>=0 && grid[row-1][col-2]==temp-1){
            return true;
        }
    }
    if(col<n-2){
        if(row+1<n && grid[row+1][col+2]==temp-1){
            return true;
        }
        if(row-1>=0 && grid[row-1][col+2]==temp-1){
            return true;
        }
    }
    return false;
}

bool solve(vector<vector<int>>&grid,int temp){
    if(temp>=(grid.size()*grid.size())){
        return true;
    }
    for(int row=0;row<grid.size();row++){
        for(int col=0;col<grid.size();col++){
            if(grid[row][col]==temp){
                if(isValid(grid,row,col,temp)){
                    if(solve(grid,temp+1)){
                        return true;
                    }
                }
                return false;
            }
        }
    }
    return false;
}

bool checkMoves(vector<vector<int>>&grid){
    if(grid[0][0]!=0){
        return false;
    }
    return solve(grid,1);
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<checkMoves(grid)<<endl;
}