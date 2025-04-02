#include<iostream>
#include<vector>
using namespace std;

bool reachAtEnd(vector<int> v){
    int maxIndex = 0;
    for(int i=0;i<v.size();i++){
        if(i>maxIndex) return false;
        maxIndex = max(maxIndex,i+v[i]);
        if(maxIndex>=v.size()-1){
            return true;
        }
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    vector<int>  v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<reachAtEnd(v)<<endl; 
}