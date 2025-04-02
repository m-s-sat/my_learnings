#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='*'||ch=='/') return 2;
    else if(ch=='+'||ch=='-') return 1;
    return -1;
}

void reverse(string &s){
    int start = 0;
    int end = s.length()-1;
    while(start<=end){
        swap(s[start],s[end]);
        start++,end--;
    }
}

string infixToPrefix(string s){
    stack<char> st;
    string ans = "";
    reverse(s);
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') s[i]=')';
        else if(s[i]==')') s[i]='(';
    }
    for(int i=0;i<s.length();i++){
        if((s[i]>='A' && s[i]<='Z')||(s[i]>='a' && s[i]<='z')||(s[i]>='0' && s[i]<='9')){
            ans+=s[i];
        }
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(st.empty()==0 && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            if(s[i]=='^'){
                while(st.empty()==0 && priority(s[i])<=priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            else{
                while(st.empty()==0 && priority(s[i])<priority(st.top())){
                    ans+=st.top();
                    st.pop();
                }
            }
            st.push(s[i]);
        }
    }
    while(st.empty()==0){
        ans+=st.top();
        st.pop();
    }
    reverse(ans);
    return ans;
}

int main(){
    string s;
    cin>>s;
    cout<<infixToPrefix(s)<<endl;
}