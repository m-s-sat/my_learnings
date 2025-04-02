#include<iostream>
#include<vector>
using namespace std;

long long maxSum(vector<int>&input){
    long long sum = 0,maxi = -999999999999;
    for(int i=0;i<input.size();i++){
        sum+=input[i];
        if(sum>maxi){
            maxi = sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    if(maxi<0){
        return 0;
    }
    return maxi;
}

int main(){
    int n;
    cin>>n;
    vector<int>input(n);
    for(int i=0;i<n;i++){
        cin>>input[i];
    }
    long long ans = maxSum(input);
    cout<<ans<<endl;
}