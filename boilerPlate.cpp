#include <iostream>
using namespace std;

class leaf {
public:
    int data;
    leaf* left;
    leaf* right;

    leaf(int d) {
        this->data = d;
        this->left = this->right = NULL;
    }
};

leaf* buildTree() {
    int input;
    cin >> input;

    if (input == -1) return NULL;

    leaf *node = new leaf(input);
    node->left = buildTree();
    node->right = buildTree();

    return node ;
}

void showTree(leaf* node) {
    // base case
    if (node == NULL) return;

    // recursive case
    if (node->left != NULL) {
        showTree(node->left);
    }
    cout << node->data << " ";
    if (node->right != NULL) {
        showTree(node->right);
    }

    return;
}

int main(void) {
    leaf* tree = buildTree();
    showTree(tree);

    return 0;
}
