#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,k;
    int arr[100];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> temp;
    int mini = INT16_MAX; 
    for(int i=0;i<(n-k+1);i++){
        int sum=0;
        for(int j=i;j<(k+i);j++){
            sum+=arr[j];
        }
        temp.push_back(sum);
    }
    for(int i=0;i<temp.size();i++){
        if(temp[i]<mini){
            mini = temp[i];
        }
    }
    cout<<mini<<endl;
}