#include<iostream>
#include<vector>
using namespace std;

void sub_sets(vector<int> arr,vector<int> ans,int i){
    if(i==arr.size()){
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    ans.push_back(arr[i]);
    sub_sets(arr,ans,i+1);
    ans.pop_back();
    sub_sets(arr,ans,i+1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sub_sets(arr,ans,0);
}