// #include<iostream>
// #include<vector>
// using namespace std;

// vector<int> merge_sort_arr(int arr1[],int size1,int arr2[],int size2){
//     vector<int> sorted;
//     int s1 = 0;
//     int s2 = 0;
//     while(s1<size1 && s2<size2){
//         if(arr1[s1]>arr2[s2]){
//             sorted.push_back(arr2[s2]);
//             s2++;
//         }
//         else{
//             sorted.push_back(arr1[s1]);
//             s1++;
//         }
//     }
//     if(s1<size1){
//         for(int i=s1;i<size1;i++){
//             sorted.push_back(arr1[i]);
//         }
//     }
//     else if(s2<size2){
//         for(int i=s2;i<size2;i++){
//             sorted.push_back(arr2[i]);
//         }
//     }
//     return sorted;
// }

// int main(){
//     int arr1[100],arr2[100];
//     int size1,size2;
//     cin>>size1>>size2;
//     for(int i=0;i<size1;i++){
//         cin>>arr1[i];
//     }
//     for(int i=0;i<size2;i++){
//         cin>>arr2[i];
//     }
//     vector<int> ans = merge_sort_arr(arr1,size1,arr2,size2);
//     for(int i=0;i<ans.size();i++){
//         cout<<ans[i]<<" ";
//     }

// }

// merge in same array;

// #include<iostream>
// using namespace std;

// int main(){
//     int arr[5]={1,2,3,4,5};
//     for(int i=5;i>=2;i--){
//         arr[i-1]=arr[i+1];
//     }
//     for(int i=0;i<5;i++){
//         cout<<arr[i]<<" ";
//     }
// }

// void sorted(int nums1[],int m,int nums2[],int n){
//     int s1=0;
//     int s2=0;
//     while(s1<m&&s2<n){
//         if(nums1[s1]<nums2[s2]){
//             for(int i=m;i>=s1;i--){

//             }
//         }
//     }
// }

// int main(){
//     int nums1[100],nums2[100],m,n;
//     cin>>m>>n;
//     for(int i=0;i<m;i++){
//         cin>>nums1[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>nums2[i];
//     }
// }

#include<iostream>
using namespace std;

int index_peak(int arr[],int size){
    int s=0;
    int e=size-1;
    int mid = e+(s-e)/2;
    while(s<e){
        if(arr[mid]<arr[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid = e+(s-e)/2;
    }
    return s;
}

int main(){
    int arr[100];
    int size;
    cin>>size;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int index  = index_peak(arr,size);
    cout<<index;
}















