#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

vector<vector<int>> sum3(vector<int>arr){
    vector<vector<int>>ans;
    set<vector<int>>nums;
    for(int i=0;i<arr.size();i++){
        set<int>st;
        for(int j=i+1;j<arr.size();j++){
            int target = -(arr[i]+arr[j]);
            if(st.find(target)!=st.end()){
                vector<int>temp={arr[i],arr[j],target};
                sort(temp.begin(),temp.end());
                nums.insert(temp);
            }
            else{
                st.insert(arr[j]);
            }
        }
    }
    ans = {nums.begin(),nums.end()};
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> ans = sum3(arr);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}