#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&nums,vector<vector<int>>&ans,int i){
    if(i>=nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        solve(nums,ans,i+1);
        swap(nums[i],nums[j]);
    }
}

vector<vector<int>> permutations(vector<int>&nums){
    vector<vector<int>> ans;
    solve(nums,ans,0);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>> ans = permutations(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}