#include<iostream>
using namespace std;

bool isPresent(int arr[][3],int target, int row, int col){
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            if(arr[row][col]==target){
                return 1;
            }
        }
    }
    return 0;
}

void printSum(int arr[][3], int row, int col){
    cout<<"Printing sum :- "<<endl;
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<3;col++){
            sum = sum + arr[row][col];
        }
        cout<<sum<<" ";
    }
}

int largestrowsum(int arr[][3], int row, int col){
    int maxi = -1;
    int row_number = 0;
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<3;col++){
            sum = sum + arr[row][col];
        }
        if(sum>maxi){
            maxi = sum;
            row_number = row + 1;
        }
    }
    cout<<"Maximum sum :- "<<maxi<<endl;
    return row_number;
}

int main(){
    // create 2d array
    int arr[3][3];
    // column wise inputs
    // int arr1[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // row wise inputs
    // int arr2[3][4] = {{1,11,111,1111},{2,22,222,2222},{3,33,333,3333}};

    // taking row wise inpur
    cout<<"Enter the elements :- "<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cin>>arr[row][col];
        }
    }

    // taking column wise input
    // for(int col=0;col<4;col++){
    //     for(int row=0;row<3;row++){
    //         cin>>arr[row][col];
    //     }
    // } 
    
    // print
    cout<<"Printing array :- "<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter a target to found :- ";
    int target;
    cin>>target;
    if(isPresent(arr,target,3,3)){
        cout<<"Element found"<<endl;
    }
    else{
        cout<<"Element not found"<<endl;
    }
    printSum(arr, 3, 3);
    cout<<"row number :- "<<largestrowsum(arr,3,3);
    return 0;
}