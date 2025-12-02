#include<iostream>
#include<vector>
using namespace std;

class Node{
public :
    int data;
    Node* prev;
    Node* next;

    Node(int value){
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList{
public:
    Node* head;
    Node* tail;

    // Convert array to doubly linked list
    Node* arrayToDoublyLinkedList(vector<int>& arr){
        if(arr.empty()){
            return nullptr;
        }

        head = new Node(arr[0]);
        Node* temp = head;

        int size = arr.size();
        for(int i = 1; i < size; i++){
            Node* newNode = new Node(arr[i]);
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode; 
        }

        tail = temp;
        return head;
    }

    // Insert at beginning
    Node* insertAtHead(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return head;
        }

        head->prev = newNode;
        newNode->next = head;
        head = newNode;

        return head;
    }

    // Insert at end
    Node* insertAtTail(int data){
        Node* newNode = new Node(data);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
            return tail;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

        return tail;
    }

    // Insert at a specific position (1-indexed)
    Node* insertAtPosition(int data, int position){

        if(position < 1){
            return head;
        }

        if(position == 1){
            return insertAtHead(data);
        }

        Node* newNode = new Node(data);
        Node* temp = head;
        int currentPosition = 1;

        while(temp != nullptr && currentPosition < position - 1 ){
            temp = temp->next;
            currentPosition++;
        }

        if(temp == nullptr){
            return head;
        }

        if(temp->next == nullptr){
            return insertAtTail(data);
        }

        Node* nextNode = temp->next;

        temp->next = newNode;
        newNode->prev = temp;

        newNode->next = nextNode;
        nextNode->prev = newNode;

        return head;
    }

    // Delete the first node
    Node* deleteAtHead(){
        if(head == nullptr){
            return head;
        }

        if(head->next == nullptr){
            delete head;
            head = nullptr;
            tail = nullptr;
            return head;
        }

        head = head->next;
        delete head->prev;
        head->prev = nullptr;

        return head;
    }

    // Delete the last node
    Node* deleteAtTail(){
        if(head == nullptr || tail == nullptr){
            return head;
        }

        if(head->next == nullptr){
            delete head;
            head = nullptr;
            tail = nullptr;
            return head;
        }

        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;

        return head;
    }

    // Delete node at given position (1-indexed)
    Node* deleteAtPosition(int position){
        if(head == nullptr){
            return head;
        }

        if(position < 1){
            return head;
        }

        if(position == 1){
            return deleteAtHead();
        }

        Node* temp = head;
        int index = 1;

        while(temp != nullptr && index < position - 1){
            temp = temp->next;
            index++;
        }

        if(temp == nullptr || temp->next == nullptr){
            return head;
        }

        Node* toDelete = temp->next;

        if (toDelete->next == nullptr) {
            temp->next = nullptr;
            delete toDelete;
            return head;
        }

        temp->next = temp->next->next;
        temp->next->prev = temp;

        delete toDelete;

        return head;
    }

    // Print DLL from head to tail
    void displayForward(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "Null";
    }

    // Print DLL backward from tail to head
    void displayBackward(Node* tail){
        Node* temp = tail;
        while(temp != nullptr){
            cout << temp -> data << "->";
            temp = temp->prev;
        }

        cout << "Null";
    }
};

int main(){

    vector<int> arr = {1,2,3,4,6,7,8,9};


    DoublyLinkedList dll;

    Node* head = dll.arrayToDoublyLinkedList(arr);

    cout << "Traversal from head : ";
    dll.displayForward(head);

    cout << endl;
    cout << "Traversal from tail : ";
    dll.displayBackward(dll.tail);

    cout << endl;
    cout << "Insertion at head : ";
    head = dll.insertAtHead(0);
    dll.displayForward(head);

    cout << endl;
    cout << "Insertion at tail : ";
    dll.insertAtTail(10);
    dll.displayBackward(dll.tail);

    cout << endl;
    cout << "Insertion at position 6 : ";
    dll.insertAtPosition(5, 6);
    dll.displayForward(dll.head);

    cout << endl;
    cout << "Deletion at Head : ";
    head = dll.deleteAtHead();
    dll.displayForward(head);

    cout << endl;
    cout << "Deletion at Tail : ";
    head = dll.deleteAtTail();
    dll.displayForward(head);

    cout << endl;
    cout << "Deletion at Position 5 : ";
    head = dll.deleteAtPosition(5);
    dll.displayForward(head);

    return 0;

}