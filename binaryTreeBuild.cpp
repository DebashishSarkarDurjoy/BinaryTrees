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

    Node* newNode = new Node(input);
    newNode->left = buildTree();
    newNode->right = buildTree();

    return newNode;
}

int main(void) {
    Node* root = buildTree();

    return 0;
}
