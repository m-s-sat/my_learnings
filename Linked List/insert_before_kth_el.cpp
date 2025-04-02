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

Node* addElementBeforek(Node* head,int el,int k){
    if(head==nullptr){
        return nullptr;
    }
    if(head->next==nullptr){
        if(k==1){
            Node* newHead = new Node(el,head,nullptr);
            head->back = newHead;
            return newHead;
        }
        return head;
    }
    int cnt=0;
    Node* temp = head;
    while(temp){
        cnt++;
        if(cnt==k-1){
            break;
        }
        temp = temp->next;
    }
    Node* front = temp->next;
    Node* newNode = new Node(el,front,temp);
    temp->next = front->back = newNode;
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
    int n,el,k;
    cin>>n>>el>>k;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Node* head = convertArraytoDLL(nums);
    head = addElementBeforek(head,el,k);
    printDLL(head);
}