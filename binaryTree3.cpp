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

int height(leaf* node) {
    // base case
    if (node == NULL) {
        return 0;
    }

    // recursive case
    int h_left = height(node->left);
    int h_right = height(node->right);

    return 1 + max(h_left, h_right);
}

int diameter(leaf* node) {
    // base case
    if (node == NULL) {
        return 0;
    }

    // recursive case
    int d1 = height(node->left) + height(node->right);
    int d2 = diameter(node->left);
    int d3 = diameter(node->right);

    return max(d1, max(d2, d3));
}

int main(void) {
    leaf* tree = buildTree();
    showTree(tree);
    cout << "Height: " << height(tree) << endl;
    cout << "Diameter: " << diameter(tree) << endl;

    return 0;
}
