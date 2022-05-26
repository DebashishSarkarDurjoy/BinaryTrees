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
pair<int, int> optDiameter(leaf* node) {
    pair<int, int> p;
    if (node == NULL) {
        p.first = 0; // height
        p.second = 0; // diameter
        return p;
    }

    pair<int, int> Left = optDiameter(node->left);
    pair<int, int> Right = optDiameter(node->right);

    p.first = max(Left.first, Right.first) + 1;

    int D1 = Left.first + Right.first;
    int D2 = Left.second;
    int D3 = Right.second;

    p.second = max(D1, max(D2, D3));

    return p;
}

int main(void) {
    leaf* root = buildTree();
    showTree(root);
    cout << "\n" << "Height: " << height(root) << endl;
    cout << "Optimised Diameter: " << optDiameter(root).second << endl;

    return 0;
}
