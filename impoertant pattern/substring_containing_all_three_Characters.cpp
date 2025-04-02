#include<bits/stdc++.h>
using namespace std;

int numberOfSubstring(string s){
    int left = 0;
    int right = 0;
    map<char,int> mp;
    int count = 0;
    while(right<s.length()){
        if(mp.find(s[right])!=mp.end()) mp[s[right]] ++;
        else mp[s[right]] = 1;
        while(mp.find('a')!=mp.end() && mp.find('b')!=mp.end() && mp.find('c')!=mp.end()){
            count+=s.length()-right;
            mp[s[left]]--;
            if(mp[s[left]]==0) mp.erase(s[left]);
            left++;   
        }
        right++;
    }
    return count;
}

int main(){
    string s;
    cin>>s;
    cout<<numberOfSubstring(s)<<endl;
}