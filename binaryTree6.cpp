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

void showTree(leaf* root) {
    if (root == NULL) return;

    showTree(root->left);
    cout << root->data << " ";
    showTree(root->right);

    return ;
}

leaf* buildTree() {
    int i;
    cin >> i;

    if (i == -1) return NULL;

    leaf* node = new leaf(i);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

int height(leaf* node) {
    if (node == NULL) return 0;

    int h1 = height(node->left);
    int h2 = height(node->right);

    return max(h1, h2) + 1;
}

int main(void) {
    // leaf* root = buildTree();


    leaf* root = new leaf(1);
	root->left = new leaf(2);
	root->right = new leaf(3);
	root->left->left = new leaf(4);
	root->left->right = new leaf(5);
	root->right->right = new leaf(6);
	root->left->right->left = new leaf(7);
	root->left->right->right = new leaf(8);
	root->left->right->right->left = new leaf(9);
	root->left->right->right->right = new leaf(10);

    showTree(root);

    return 0;
}
