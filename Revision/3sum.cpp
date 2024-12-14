#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

void sum3(vector<int> arr,vector<int> ans,int sum,int i,vector<vector<int>> &final_ans,set<vector<int>> temp){
    if(i>arr.size()){
        if(sum==0&&ans.size()==3){
            sort(ans.begin(),ans.end());
            if(temp.find(ans)==temp.end()){
                temp.insert(ans);
                final_ans.push_back(ans);
            }
        }
        return ;
    }
    ans.push_back(arr[i]);
    sum+=arr[i];
    sum3(arr,ans,sum,i+1,final_ans,temp);

    ans.pop_back();
    sum-=arr[i];
    sum3(arr,ans,sum,i+1,final_ans,temp);
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> ans;
    set<vector<int>> temp;
    vector<vector<int>> final_ans;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sum3(arr,ans,0,0,final_ans,temp);
    for(int i=0;i<final_ans.size();i++){
        for(int j=0;j<3;j++){
            cout<<final_ans[i][j]<<" ";
        }
        cout<<endl;
    }
}