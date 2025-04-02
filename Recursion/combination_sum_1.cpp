#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void combination_sum(vector<int>&arr,vector<vector<int>>&ans,vector<int>temp,int i,int sum,int target){
    if(i>=arr.size()||sum>=target){
        if(sum==target){
            ans.push_back(temp);
        }
        return ;
    }
    temp.push_back(arr[i]);
    sum+=arr[i];
    combination_sum(arr,ans,temp,i,sum,target);
    temp.pop_back();
    sum-=arr[i];
    combination_sum(arr,ans,temp,i+1,sum,target);
}

int main(){
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> temp;
    vector<vector<int>> ans;
    sort(arr.begin(),arr.end());
    combination_sum(arr,ans,temp,0,0,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}