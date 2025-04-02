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

Node* convertArray2DLL(vector<int>& nums){
    Node* head = new Node(nums[0]);
    Node* prev = head;
    for(int i=1;i<nums.size();i++){
        Node* temp = new Node(nums[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* deleteTailDLL(Node* head){
    // Node* temp = head;
    // Node* prev = nullptr;
    // while(temp){
    //     if(temp->next==nullptr){
    //         prev->next = nullptr;
    //         temp->back = nullptr;
    //         free(temp);
    //         break;
    //     }
    //     prev = temp;
    //     temp = temp->next;
    // }
    Node* tail = head;
    while(tail->next){
        tail = tail->next;
    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    free(tail);
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
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
    Node* head = convertArray2DLL(nums);
    head = deleteTailDLL(head);
    printDLL(head);
}