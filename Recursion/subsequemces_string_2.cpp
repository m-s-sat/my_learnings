#include<iostream>
#include<string>
#include<vector>
using namespace std;

void permutation(string &str1,string &str2,vector<string>&ans,int i){
    if(i>=str1.length()){
        if(str2.length()>0){
            ans.push_back(str2);
        }
        return ;
    }

    str2.push_back(str1[i]);
    permutation(str1,str2,ans,i+1);

    str2.pop_back();
    permutation(str1,str2,ans,i+1);
}

int main(){
    string str1,str2;
    vector<string> ans;
    cin>>str1;
    permutation(str1,str2,ans,0);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}