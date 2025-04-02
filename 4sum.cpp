#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

vector<vector<int>> foursum(vector<int>nums,int target){
    set<vector<int>> hashing;
    for(int i=0;i<nums.size();i++){
        for(int j=i+1;j<nums.size();j++){
            for(int k=j+1;k<nums.size();k++){
                for(int l=k+1;l<nums.size();l++){
                    if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        sort(temp.begin(),temp.end());
                        hashing.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans = {hashing.begin(),hashing.end()};
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> nums(n);
    for(int i=0;i<nums.size();i++){
        cin>>nums[i];
    }
    vector<vector<int>> ans = foursum(nums,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<4;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}