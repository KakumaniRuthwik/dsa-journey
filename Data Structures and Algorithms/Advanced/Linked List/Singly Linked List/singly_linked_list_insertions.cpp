#include<iostream>
#include<vector>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

pair<Node*,Node*> arrayToLinkedList(vector<int>& arr){
    
    int size = arr.size();

    if(size == 0){
        return {nullptr, nullptr};
    }

    Node* head = new Node(arr[0]);
    Node* temp = head;

    Node* tail = temp;
    
    for(int i = 1; i < size; i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
        tail = temp;
    }

    return {head, tail};
}

void linkedListTraversal(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp -> next;
    }

    cout << "NULL";
}

void insertAtBeginning(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9};

    auto [head, tail] = arrayToLinkedList(arr);
    
    cout << endl;
    
    cout << "Linked List before adding Elements at beginning : " ;
    linkedListTraversal(head);
    
    cout << endl;
    
    insertAtBeginning(head, 0);
    cout << "Linked List after adding Elements at beginning : " ;
    linkedListTraversal(head);

    insertAtEnd(tail, 10);
    cout << "Linked List after adding Elements at end : " ;
    linkedListTraversal(head);
    
    return 0;
}