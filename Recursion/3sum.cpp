#include<iostream>
#include<vector>
#include<set>
using namespace std;

void sum3_sub_sequences(vector<int> arr,vector<int> ans,vector<int>& final_ans,int i,int k,int sum){
    if(i>=arr.size()){
        if(sum==k&&ans.size()==3){
            for(int i=0;i<3;i++){
                final_ans.push_back(arr[i]);
            }
        }
        return ;
    }
    ans.push_back(arr[i]);
    sum+=arr[i];
    sum3_sub_sequences(arr,ans,final_ans,i+1,k,sum);
    ans.pop_back();
    sum-=arr[i];
    sum3_sub_sequences(arr,ans,final_ans,i+1,k,sum);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> ans;
    vector<int> final_ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sum3_sub_sequences(arr,ans,final_ans,0,k,0);
    for(int i=0;i<final_ans.size();i++){
        cout<<final_ans[i]<<" ";
    }
}