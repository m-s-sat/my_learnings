#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* back;
    public:
        Node(int data1,Node* next1,Node* back1){
            data = data1;
            next = next1;
            back = back1;
        }
    public:
        Node(int data1){
            data = data1;
            next = nullptr;
            back = nullptr;
        }
};

Node* convertArraytoDLL(vector<int>&nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteNodeDLL(Node* head,int val){
    if(head==nullptr) return head;
    Node* temp = head;
    while(temp){
        if(temp->data==val){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* front = temp->next;
    if(front==nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
    }
    else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        free(temp);
    }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    int n,val;
    cin>>n>>val;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArraytoDLL(nums);
    head = deleteNodeDLL(head,val);
    printDLL(head);
}