#include<iostream>
#include<vector>
using namespace std;

bool print_any_sub_sequences(vector<int>arr,vector<int> ans,int k,int sum,int i){
    if(i>=arr.size()){
        if(k==sum){
            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<endl;
            return true;
        }
        return false;
    }
    ans.push_back(arr[i]);
    sum+=arr[i];
    if(print_any_sub_sequences(arr,ans,k,sum,i+1)==true){
        return true;
    }
    ans.pop_back();
    sum-=arr[i];
    if(print_any_sub_sequences(arr,ans,k,sum,i+1)==true){
        return true;
    }
    return false;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_any_sub_sequences(arr,ans,k,0,0);
}