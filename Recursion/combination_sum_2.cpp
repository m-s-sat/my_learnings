#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans,int target,int i){
    if(i>=arr.size() || target<=0){
        if(target==0){
            ans.push_back(ds);
        }
        return ;
    }
    for(int j=i;j<arr.size();j++){
        if(j>i && arr[j]==arr[j-1]) continue;
        if(arr[j]>target) break;
        ds.push_back(arr[j]);
        solve(arr,ds,ans,target-arr[j],j+1);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>&arr,int target){
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>ds;
    solve(arr,ds,ans,target,0);
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ans = combinationSum2(arr,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}