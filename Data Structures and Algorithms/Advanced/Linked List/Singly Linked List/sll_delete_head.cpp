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

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    if(position == 0){
        insertAtBeginning(head, data);
        return;
    }

    Node* temp = head;
    int index = 0;

    while(temp != nullptr && index < position - 1){
        temp = temp->next;
        index++;
    }

    if(temp == nullptr){
        cout << "Position out of bounds";
        return;
    }
    
    if(temp->next == nullptr){
        insertAtEnd(tail, data);
        return;
    }

    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletionAtBeginning(Node* &head){

    if(head == nullptr){
        return;
    }
    
    Node* temp = head;
    head = head->next;
    delete temp;
}

int main(){

    vector<int> arr = {1,2,3,4,6,7,8,9};

    auto [head, tail] = arrayToLinkedList(arr);
    
    cout << endl;
    
    cout << "Linked List before adding Elements at beginning : " ;
    linkedListTraversal(head);
    
    cout << endl;
    
    insertAtBeginning(head, 0);
    cout << "Linked List after adding Elements at beginning : " ;
    linkedListTraversal(head);
    
    cout << endl;

    insertAtEnd(tail, 10);
    cout << "Linked List after adding Elements at end : " ;
    linkedListTraversal(head);
   
    cout << endl;
   
    insertAtPosition(head, tail, 5, 5);
    cout << "Linked List after adding Elements at position 5 : " ;
    linkedListTraversal(head);

    cout << endl;

    deletionAtBeginning(head);
    cout << "Linked List after deleting element at start : ";
    linkedListTraversal(head);
    
    cout << endl;
    
    return 0;
}