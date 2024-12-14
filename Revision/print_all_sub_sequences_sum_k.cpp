#include<iostream>
#include<vector>
using namespace std;

void print_all_sub_sequences_sum_is_k(vector<int> arr,vector<int> ans,int k,int sum,int i){
    if(i>=arr.size()){
        if(sum==k){
            for(auto it:ans){
                cout<<it<<" ";
            }
            cout<<endl;
        }
        return ;
    }

    ans.push_back(arr[i]);
    sum+=arr[i];
    print_all_sub_sequences_sum_is_k(arr,ans,k,sum,i+1);

    ans.pop_back();
    sum-=arr[i];
    print_all_sub_sequences_sum_is_k(arr,ans,k,sum,i+1);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    print_all_sub_sequences_sum_is_k(arr,ans,k,0,0);
}