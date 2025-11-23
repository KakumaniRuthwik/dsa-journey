#include<iostream>
#include<vector>
using namespace std;

// Using Struct
/* struct Node{

    public:
        int data;
        Node* next;

    public :
        Node(int value){
            data = value;
            next = nullptr;
        }
    };  
*/

// Using Class
class Node{

public:
    int data;
    Node* next;

public:
    Node(int value){
        data = value;
        next = nullptr;
    }
};


int main(){

    vector<int> arr = {2, 5, 8, 7};
    Node* y = new Node(arr[0]);
    cout << y -> data;

    return 0;
}