#include <bits/stdc++.h>
using namespace std;

// BST Node Definition
class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (root == nullptr)
        return new TreeNode(val);

    TreeNode* curr = root;
    while (true) {
        if (val < curr->data) {
            if (curr->left == nullptr) {
                curr->left = new TreeNode(val);
                break;
            }
            curr = curr->left;
        } else {
            if (curr->right == nullptr) {
                curr->right = new TreeNode(val);
                break;
            }
            curr = curr->right;
        }
    }
    return root;
}

// Search in BST
TreeNode* searchBST(TreeNode* root, int key) {
    while (root != nullptr) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

// Inorder Traversal
void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Delete from BST
TreeNode* findMin(TreeNode* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

TreeNode* deleteBST(TreeNode* root, int key) {
    if (root == nullptr) return nullptr;

    if (key < root->data) {
        root->left = deleteBST(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteBST(root->right, key);
    } 
    else {
        // Node found
        if (root->left == nullptr) return root->right;
        if (root->right == nullptr) return root->left;

        TreeNode* succ = findMin(root->right);
        root->data = succ->data;
        root->right = deleteBST(root->right, succ->data);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;

    // Insert nodes
    vector<int> values = {8, 4, 12, 2, 6, 10, 14};
    for (int v : values)
        root = insertBST(root, v);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    // Search
    int key = 10;
    cout << "Searching " << key << ": ";
    cout << (searchBST(root, key) ? "Found" : "Not Found") << endl;

    // Floor & Ceil
    int k = 11;
    vector<int> ans = floorCeilOfBST(root, k);
    cout << "Floor = " << ans[0] << ", Ceil = " << ans[1] << endl;

    // Delete
    root = deleteBST(root, 12);
    cout << "After deleting 12, Inorder: ";
    inorder(root);
    cout << endl;

    return 0;
}
