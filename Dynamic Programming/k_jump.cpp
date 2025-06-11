#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>heights,int n,int k){
    if(n==0) return 0;
    int min_energy = INT_MAX;
    for(int i=1;i<=k;i++){
        if(i<=n){
            int jump = solve(heights,n-i,k)+abs(heights[n]-heights[n-i]);
            min_energy = min(min_energy,jump);
        }
    }
    return min_energy;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> heights(n);
    for(int i=0;i<n;i++) cin>>heights[i];
    cout<<solve(heights,n-1,k);
}