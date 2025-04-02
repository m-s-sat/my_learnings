#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    public:
        Node(int data1,Node* next1){
            data = data1;
            next = next1;
        }
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
        }
};

Node* convertArraytoLL(vector<int>nums){
    Node* head = new Node(nums[0]);
    Node* move = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        move->next = temp;
        move = temp;
    }
    return head;
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* sumLL(Node* nums1,Node* nums2){
    Node* dummyNode = new Node(-1);
    Node* curr = dummyNode;
    int carry = 0;
    while(nums1!=nullptr || nums2!=nullptr){
        int sum = carry;
        if(nums1) sum+=nums1->data;
        if(nums2) sum+=nums2->data;
        Node* newNode = new Node(sum%10);
        carry = sum/10;
        if(nums1) nums1 = nums1->next;
        if(nums2) nums2 = nums2->next;
        curr->next = newNode;
        curr = newNode;
    }
    if(carry>0){
        Node* newNode = new Node(carry);
        curr->next = newNode;
        curr = newNode;
    }
    return dummyNode->next;
}

int main(){
    int n;
    cin>>n;
    vector<int>nums1(n);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    int m;
    cin>>m;
    vector<int>nums2(m);
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    Node* head1 = convertArraytoLL(nums1);
    Node* head2 = convertArraytoLL(nums2);
    Node* ans  = sumLL(head1,head2);
    printLL(ans);
}