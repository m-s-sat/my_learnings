#include<iostream>
#include<vector>
using namespace std;

bool isPossible(vector<int> &arr,int m,int mid){
    int studentCount = 1;
    int pages = 0;
    for(int i=0;i<arr.size();i++){
        if(pages+arr[i]<=mid){
            pages+=arr[i];
        }
        else{
            studentCount++;
            if(studentCount>m || arr[i]>mid){
                return false;
            }
            pages = arr[i];
        }
    }
    return true;
}

int book_allocate(vector<int> &arr,int m){
    int s = 0;
    int e = 0;
    for(auto it:arr){
        e+=it;
    }
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPossible(arr,m,mid)){
            e=mid-1;
            ans = mid;
        }
        else{
            s=mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;

}

int find_max_pages(vector<int> &arr,int m){
    return book_allocate(arr,m);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans = find_max_pages(arr,m);
    cout<<ans<<endl;
}