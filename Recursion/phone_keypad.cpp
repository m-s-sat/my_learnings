#include<iostream>
#include<vector>
using namespace std;

void solve(string str,string temp,vector<string>&ans,int i,string values[]){
    if(i>=str.length()){
        ans.push_back(temp);
        return;
    }
    int num = str[i]-'0';
    for(int j=0;j<values[num].length();j++){
        temp.push_back(values[num][j]);
        solve(str,temp,ans,i+1,values);
        temp.pop_back();
    }
}

vector<string> letterCombination(string digit){
    string values[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;
    string temp;
    solve(digit,temp,ans,0,values);
    return ans;
}

int main(){
    string digit;
    cin>>digit;
    vector<string> ans = letterCombination(digit);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
}