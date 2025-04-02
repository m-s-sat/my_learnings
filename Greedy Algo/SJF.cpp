#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int avg_wait_time(vector<int>& arr){
    sort(arr.begin(),arr.end());
    int time = 0;
    int ans = 0;
    for(int i=0;i<arr.size();i++){
        ans+=time;
        time+=arr[i];
    }
    return ans/arr.size();
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<avg_wait_time(arr)<<endl;
}