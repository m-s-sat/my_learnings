#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(vector<int>&arr,int sum,int i,vector<int>&ans){
    if(i>=arr.size()){
        ans.push_back(sum);
        return ;
    }
    sum+=arr[i];
    solve(arr,sum,i+1,ans);
    sum-=arr[i];
    solve(arr,sum,i+1,ans);
}

vector<int> allSum(vector<int>arr){
    vector<int>ans;
    solve(arr,0,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> ans = allSum(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}