#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> two_sum(vector<int>arr,int size,int target){
    vector<pair<int,int>> element;
    int found=0;
    sort(arr.begin(),arr.end());
    int s=0;
    int e=size-1;
    while(s<e){
        if(arr[s]+arr[e]==target){
            found =1;
            pair<int,int> temp;
            temp.first = arr[s];
            temp.second = arr[e];
            element.push_back(temp);
            s++,e--;
        }
        else if(arr[s]+arr[e]<target){
            s++;
        }
        else{
            e--;
        }
    }
    if(found==0){
        pair<int,int> temp;
        temp.first=-1;
        temp.second =-1;
        element.push_back(temp);
    }
    return element;
}

int main(){
    int size,target;
    cin>>size>>target;
    vector<int> value(size,0);
    for(int i=0;i<size;i++){
        cin>>value[i];
    }
    vector<pair<int,int>> ans = two_sum(value,size,target);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<":"<<ans[i].second<<endl;
    }
}