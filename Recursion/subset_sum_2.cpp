#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>&arr,vector<vector<int>>&ans,int i,vector<int>temp){
    ans.push_back(temp);
    for(int j=i;j<arr.size();j++){
        if(j>i && arr[j]==arr[j-1]) continue;
        temp.push_back(arr[j]);
        solve(arr,ans,j+1,temp);
        temp.pop_back();
    }
}

vector<vector<int>> subset_sum_2(vector<int>arr){
    sort(arr.begin(),arr.end());
    vector<int>temp;
    vector<vector<int>> ans;
    solve(arr,ans,0,temp);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ans = subset_sum_2(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}