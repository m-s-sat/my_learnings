#include<iostream>
#include<vector>
using namespace std;

int count_sub_sequences(vector<int> arr,int i,int k,int sum){
    if(i>arr.size()){
        if(sum==k){
            return 1;
        }
        return 0;
    }
    sum+=arr[i];
    int l = count_sub_sequences(arr,i+1,k,sum);
    sum-=arr[i];
    int r = count_sub_sequences(arr,i+1,k,sum);

    return l+r;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Sum of all sub sequences which sum is "<<k<<" : "<<count_sub_sequences(arr,0,k,0)<<endl;
}