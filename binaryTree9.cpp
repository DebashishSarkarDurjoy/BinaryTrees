#include <iostream>

using namespace std;

class leaf {
public:
    int data;
    leaf* left;
    leaf* right;

    leaf(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

leaf* buildTree() {
    int input;
    cin >> input;

    if (input == -1) return NULL;

    leaf* node = new leaf(input);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

void showTree(leaf* root) {
    if (root == NULL) return;

    showTree(root->left);
    cout << root->data << " ";
    showTree(root->right);

    return ;
}

int height(leaf* root) {
    if (root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return max(left, right) + 1;
}

int main(void) {
    leaf* root = buildTree();

    showTree(root);
    cout << "Height: " << height(root) << endl;

    return 0;
}

