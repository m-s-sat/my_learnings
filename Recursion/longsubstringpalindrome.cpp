#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string s,int st,int ed){
    int left = st;
    int right = ed;
    while(left<=right){
        if(s[left]!=s[right]) return false;
        left++,right--;
    }
    return true;
}

string longestPallindrome(string s){
    int st = 0;
    int ed = s.length()-1;
    int max_size = INT_MIN;
    int max_st = ed;
    int max_ed = 0;
    while(st<=ed){
        if(checkPalindrome(s,st,ed)){
            if(max_size<ed-st+1){
                max_ed = max(max_ed,ed);
                max_size = ed-st+1;
            }
        }
        ed--;
    }
    ed = s.length()-1;
    while(st<=ed){
        if(checkPalindrome(s,st,ed)){
            if(max_size<ed-st+1){
                max_st = min(max_st,st);
                max_size = max_size,ed-st+1;
            }
        }
        st++;
    }
    st = 0;
    while(st<=ed){
        if(checkPalindrome(s,st,ed)){
            if(max_size<ed-st+1){
                max_st = min(max_st,st);
                max_ed = max(max_ed,ed);
                max_size = ed-st+1;
            }
        }
        st++,ed--;
    }
    string ans = "";
    for(int i=max_st;i<=max_ed;i++) ans+=s[i];
    if(ans.length()==0) ans.push_back(s[0]);
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<longestPallindrome(s)<<endl;
}