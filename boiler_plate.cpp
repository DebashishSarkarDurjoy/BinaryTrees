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

Node* build_tree() {
    int input;
    cin >> input;

    if (input == -1) return NULL;

    Node* node = new Node(input);
    node->left = build_tree();
    node->right = build_tree();

    return node;
}

int main(void) {
    Node* root = build_tree();

    return 0;
}
