#include<iostream>
#include<vector>
using namespace std;

string kthpermuatation(int n,int k){
    int fact=1;
    vector<int>number;
    for(int i=1;i<n;i++){
        fact=fact*i;
        number.push_back(i);
    }
    number.push_back(n);
    k=k-1;
    string ans = "";
    while(true){
        ans=ans+to_string(number[k/fact]);
        number.erase(number.begin()+k/fact);
        if(number.size()==0){
            break;
        }
        k=k%fact;
        fact=fact/number.size();
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    string ans = kthpermuatation(n,k);
    cout<<ans<<endl;
}