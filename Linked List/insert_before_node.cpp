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

void addElementBeforeNode(Node* temp,int el){
    Node* prev = temp->back;
    Node* newNode = new Node(el,temp,prev);
    prev->next = temp->back = newNode;
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
    int n,el;
    cin>>n>>el;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArraytoDLL(nums);
    addElementBeforeNode(head->next->next,el);
    printDLL(head);
}