#include<bits/stdc++.h>
using namespace std;

// brute force

int min_jump(vector<int>& arr,int j,int jumps){
    if(j>=arr.size()) return jumps;
    int ans = INT_MAX;
    for(int i=1;i<=arr[j];i++){
        ans = min(min_jump(arr,j+i,jumps+1),ans);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<min_jump(arr,0,0)<<endl;
}