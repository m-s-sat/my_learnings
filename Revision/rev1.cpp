#include<iostream>
#include<vector>
using namespace std;

void f(vector<int> &arr,vector<int> &ans,int i){
    if(i>=arr.size()){
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
        return ;
    }
    ans.push_back(arr[i]);
    f(arr,ans,i+1);

    ans.pop_back();
    f(arr,ans,i+1);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    f(arr,ans,0);
}