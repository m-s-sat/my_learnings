#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> print_all_subarray(vector<int>&nums){
    vector<vector<int>> ans;
    for(int i=0;i<nums.size();i++){
        for(int j=i;j<nums.size();j++){
            vector<int> temp;
            for(int k=i;k<=j;k++){
                temp.push_back(nums[k]);
            }
            ans.push_back(temp);
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>> ans = print_all_subarray(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}