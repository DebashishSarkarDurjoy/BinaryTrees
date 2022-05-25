#include <iostream>
using namespace std;

class leaf {
public:
    int data;
    leaf* left;
    leaf* right;

    leaf(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

leaf* buildTree() {
    int input;
    cin >> input;

    if (input == -1) {
        return NULL;
    }

    leaf* node = new leaf(input);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

void showTree(leaf* node) {
    if (node == NULL) return;

    showTree(node->left);
    cout << node->data << " ";
    showTree(node->right);

    return ;
}

int main(void) {
    leaf* root = buildTree();
    showTree(root);

    return 0;
}
