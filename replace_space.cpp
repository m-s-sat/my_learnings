#include<iostream>/.
using namespace std;

string space_remover(string s){
    string temp = "";
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else{
            temp.push_back(s[i]);
        }
    }
    return temp;
}

int main(){
    string n;
    cout<<"Write Sentences :- ";
    getline(cin,n);
    cout<<space_remover(n);
}