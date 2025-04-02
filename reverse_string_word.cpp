#include<iostream>
using namespace std;

void reverseStringWords(string &str){
    int s=0;
    int e=str.length()-1;
    while(s<=e){
        swap(str[s],str[e]);
        s++,e--;
    }
    cout<<str<<endl;
    int i=0;
    while(i<str.length()){
        int s1=i;
        int e1=0;
        for(int j=0;str[j]!=' ';j++){
            if(str[j]=='\0'){
                break;
            }
            e1++;
        }
        int k = e1;
        int e2 = e1-1;
        while(s1<=e2){
            swap(str[s1],str[e1]);
            s1++,e2--;
        }
        i+=k;
    }
}

int main(){
    string s;
    getline(cin,s);
    reverseStringWords(s);
    cout<<s<<endl;
}