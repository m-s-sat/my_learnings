#include<iostream>
#include<vector>
using namespace std;

int left_most(vector<int> arr,int n,int x){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;
    int ans = 0;
    while(s<=e){
        if(arr[mid]==x){
            ans = mid;
            e=mid-1;
        }
        else if(arr[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int right_most(vector<int> arr,int n,int x){
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;
    int ans = 0;
    while(s<=e){
        if(arr[mid]==x){
            ans = mid;
            s = mid+1;
        }
        else if(arr[mid]>x){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int size,x;
    cin>>size>>x;
    vector<int> arr(size,0);
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int left = left_most(arr,size,x);
    int right = right_most(arr,size,x);
    cout<<left<<" "<<right;
}