#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafeDown(vector<vector<int>> &maze,string &s, int row,int col,vector<vector<bool>> &visited){
    if(row<maze.size()){
        if(maze[row][col]==0||visited[row][col]==true){
            return false;
        }
        return true;
    }
    return false;
}

bool isSafeUp(vector<vector<int>> &maze,string &s,int row,int col,vector<vector<bool>> &visited){
    if(row>=0){
        if(maze[row][col]==0||visited[row][col]==true){
            return false;
        }
        return true;
    }
    return false;
}

bool isSafeRight(vector<vector<int>> &maze,string &s,int row,int col,vector<vector<bool>> &visited){
    if(col<maze.size()){
        if(maze[row][col]==0||visited[row][col]==true){
            return false;
        }
        return true;
    }
    return false;
}

bool isSafeLeft(vector<vector<int>> &maze,string &s,int row,int col,vector<vector<bool>> &visited){
    if(col>=0){
        if(maze[row][col]==0||visited[row][col]==true){
            return false;
        }
        return true;
    }
    return false;
}

void path(vector<vector<int>> &maze,int n,vector<string> &ans,string &s,int row,int col,vector<vector<bool>>&visited){
    if(col==n-1 && row==n-1){
        ans.push_back(s);
        return ;
    }
    visited[row][col] = true;
    if(isSafeDown(maze,s,row+1,col,visited)){
        s.append("D");
        path(maze,n,ans,s,row+1,col,visited);
    }
    if(isSafeRight(maze,s,row,col+1,visited)){
        s.append("R");
        path(maze,n,ans,s,row,col+1,visited);
    }
    if(isSafeLeft(maze,s,row,col-1,visited)){
        s.append("L");
        path(maze,n,ans,s,row,col-1,visited);
    }
    if(isSafeUp(maze,s,row-1,col,visited)){
        s.append("U");
        path(maze,n,ans,s,row-1,col,visited);
    }
    s.pop_back();
    visited[row][col] = false;
}

vector<string> find_path(vector<vector<int>>&maze,int n){
    string s;
    vector<string> ans;
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    path(maze,n,ans,s,0,0,visited);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> maze(n,vector<int>(n));
    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            cin>>maze[row][col];
        }
    }
    vector<string>ans = find_path(maze,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}