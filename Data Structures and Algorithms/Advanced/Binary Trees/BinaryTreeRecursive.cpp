#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// DFS (Depth First Search)
void inorder(Node* root){
    if(root == nullptr){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == nullptr){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr){
        return;
    }

    postorder(root->left);
    postorder(root->right);

    cout << root->data << " ";
}


// BFS (Breadth First Search)
vector<vector<int>> levelorder(Node* root){

    vector<vector<int>> result;

    if(root == nullptr){
        return result;
    }

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        vector<int> level;
        int size = q.size();

        for(int i = 0; i < size; i++){
            Node* node = q.front();
            q.pop();
            
            if(node->left != nullptr){
                q.push(node->left);
            }

            if(node->right != nullptr){
                q.push(node->right);
            }

            level.push_back(node->data);
        }

        result.push_back(level);
    }

    return result;
}

int main(){
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // DFS (Depth First Search)
    // In-Order Traversal
    cout << "Inorder Traversal: ";
    inorder(root);
    
    // Pre-Order Traversal
    cout << endl;
    cout << "Preorder Traversal: ";
    preorder(root);

    // Post-Order Traversal
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(root);

    // BFS (Breadth First Search)
    cout << endl;
    cout << "Levelorder Traversal: ";
    vector<vector<int>> levels = levelorder(root);

    for (auto &level : levels) {
        for (int x : level) {
            cout << x << " ";
        }
    }


    return 0;
}