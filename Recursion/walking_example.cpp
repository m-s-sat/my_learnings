#include<iostream>
using namespace std;

void reachDest(int src,int dest){
    cout<<src<<" "<<dest<<endl;
    if(src==dest){
        cout<<"Reached"<<endl;
        return ;
    }
    reachDest(src+1,dest);
}

int main(){
    int dest = 10;
    int s = 1;
    reachDest(s,dest);
}