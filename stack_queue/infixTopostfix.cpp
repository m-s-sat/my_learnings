#include<iostream>
#include<stack>
using namespace std;

int priority(char ch){
    if(ch=='^') return 3;
    else if(ch=='/'||ch=='*') return 2;
    else if(ch=='+'||ch=='-') return 1;
    return -1;
}

string infixToPostfix(string s){
    stack<char> st;
    string ans="";
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z')||(s[i]>='0' && s[i]<='9')){
            st.push(s[i]);
        }
        else if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(st.empty()==0 && st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            if(st.empty()==0) st.pop();
        }
        else{
            while(st.empty()==0 && priority(s[i])<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(st.empty()==0){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<infixToPostfix(s)<<endl;
    return 0;
}