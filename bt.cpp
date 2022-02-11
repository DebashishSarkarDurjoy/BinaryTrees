#include <iostream>
using namespace std;

class Node {
public:
    
    int val;
    Node* left;
    Node* right;

    Node(int v) {
        this->val = v;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int i;
    cin >> i;
    if (i == -1) return NULL;

    Node* newNode = new Node(i);
    newNode->left = buildTree();
    newNode->right = buildTree();

    return newNode;
}

int main(void) {
    Node* root = buildTree();


    return 0;
}
