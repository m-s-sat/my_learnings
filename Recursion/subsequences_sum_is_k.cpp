#include<iostream>
#include<vector>
using namespace std;

void sub_sequences(vector<int> arr,vector<int> ans,int k,int i,int sum){
    if(i>=arr.size()){
        if(sum==k){
            for(auto it : ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return ;
    }

    ans.push_back(arr[i]);
    sum+=arr[i];
    sub_sequences(arr,ans,k,i+1,sum);
    ans.pop_back();
    sum-=arr[i];
    sub_sequences(arr,ans,k,i+1,sum);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sub_sequences(arr,ans,k,0,0);
}