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

    leaf* newNode = new leaf(input);
    newNode->left = buildTree();
    newNode->right = buildTree();

    return newNode;
}

void showTree(leaf* node) {
    if (node == NULL) {
        return;
    }

    showTree(node->left);
    cout << node->data << " ";
    showTree(node->right);

    return ;
}

int height(leaf* node) {
    if (node == NULL) return 0;

    int h1 = height(node->left);
    int h2 = height(node->right);

    return max(h1, h2) + 1;
}

// optimised diameter using pair
pair<int, int> optDiameter()

int main(void) {
    leaf* root = buildTree();
    showTree(root);
    cout << "\n" << "Height: " << height(root) << endl;

    return 0;
}
