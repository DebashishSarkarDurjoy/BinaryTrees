#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree() {
    int input;
    cin >> input;

    if (input == -1) return NULL;

    Node* node = new Node(input);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

int main(void) {
    Node* root = buildTree();

    return 0;
}
