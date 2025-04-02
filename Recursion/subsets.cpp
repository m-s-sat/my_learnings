#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>&temp,int i){
    if(i>=nums.size()){
        ans.push_back(temp);
        return ;
    }
    for(int j=i;j<nums.size();j++){
        
    }
}

vector<vector<int>> findAllSubsets(vector<int>&nums){
    vector<int> temp;
    vector<vector<int>> ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}