#include<iostream>
#include<vector>
using namespace std;

bool print_any_sub_sequences(vector<int> arr,vector<int> ans,int i,int sum,int k){
    if(i>=arr.size()){
        if(sum==k){
            for(auto it : ans){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    ans.push_back(arr[i]);
    sum+=arr[i];
    if(print_any_sub_sequences(arr,ans,i+1,sum,k)==true){
        return true;
    }
    ans.pop_back();
    sum-=arr[i];
    if(print_any_sub_sequences(arr,ans,i+1,sum,k)==true){
        return true;
    }
    return false;
}

int  main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_any_sub_sequences(arr,ans,0,0,k);
}