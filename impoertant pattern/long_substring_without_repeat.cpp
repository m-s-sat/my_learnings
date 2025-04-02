#include<bits/stdc++.h>
using namespace std;

int longestSubstring(string s){
    int left = 0;
    int right = left;
    int maxlength = 0;
    map<char,int> mp;
    while(right<s.length()){
        if(mp.find(s[right])!=mp.end() && right>mp[s[right]]){
            left = mp[s[right]]+1;
            mp[s[right]] = right;
        }
        else{
            mp[s[right]] = right;
            maxlength = max(maxlength,right-left+1);
        }
        right++;
    }
    return maxlength;
}

int main(){
    string s;
    cin>>s;
    cout<<longestSubstring(s)<<endl;
}