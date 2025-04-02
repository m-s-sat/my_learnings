#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void printSubset(vector<int>arr,int n,int target){
    int i = 0;
    while(i<n){
        stack<int> st;
        vector<int> ans;
        int k = target;
        for(int j=i;j<n;j++){
            st.push(arr[j]);
            target = target-arr[j];
            if(target<0){
                target+=st.top();
                st.pop();
            }
            else if(target==0){
                vector<int> v;
                stack<int> temp;
                while(st.empty()==0){
                    v.push_back(st.top());
                    temp.push(st.top());
                    st.pop();
                }
                while(temp.empty()==0){
                    st.push(temp.top());
                    temp.pop();
                }
                for(int k=0;k<v.size();k++){
                    cout<<v[k]<<" ";
                }
                cout<<endl;
                v.erase(v.begin(),v.end());
                target+=st.top();
                st.pop();
            }
        }
        target = k;
        i++;
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    printSubset(arr,n,k);
}