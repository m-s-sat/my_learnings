#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>&candidates,vector<vector<int>> &ans,vector<int> &temp,int target,int sum,int i){
    if(i>=candidates.size()){
        if(sum==target){
            ans.push_back(temp);
        }
        return ;
    }

    if(sum>target){
        temp.pop_back();
        sum-=candidates[i];
        solve(candidates,ans,temp,target,sum,i+1);
    }
    else{temp.push_back(candidates[i]);
        sum+=candidates[i];
        solve(candidates,ans,temp,target,sum,i);
    }
    temp.pop_back();
    sum-=candidates[i];
    solve(candidates,ans,temp,target,sum,i+1);
}

vector<vector<int>> combinations(vector<int> &candidates,int target){
    vector<int> temp;
    vector<vector<int>> ans;
    solve(candidates,ans,temp,target,0,0);
    return ans;
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ans = combinations(arr,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}