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

Node* convertArraytoLL(vector<int>& nums){
    Node* head = new Node(nums[0]);
    Node* move = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i]);
        move->next = temp;
        move = temp;
    }
    return head
}

void printLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArraytoLL(nuums);
    printLL(head);
}