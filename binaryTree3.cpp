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

class HDpair {
public:
    int height;
    int diameter;
};

HDpair optDiameter(leaf* node) {
    HDpair Pair;
    // base case
    if (node == NULL) {
        Pair.height = Pair.diameter = 0;
        return Pair;
    }

    // recursive case
    HDpair Left = optDiameter(node->left);
    HDpair Right = optDiameter(node->right);

    int d1 = Left.diameter;
    int d2 = Right.diameter;
    int d3 = Left.height + Right.height;

    Pair.height = max(Left.height, Right.height) + 1;
    Pair.diameter = max(Pair.height, max(d1, d2));

    return Pair;
}

pair<int, bool> isHeightBalanced(leaf* node) {
    // base case
    if (node == NULL) {
        pair<int, bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }

    // recursive case
    pair<int, bool> Left = isHeightBalanced(node->left);
    pair<int, bool> Right = isHeightBalanced(node->right);
    int height = max(Left.first, Right.first) + 1;
    if (abs(Left.first - Right.first) <= 1 && Left.second && Right.second) {
        return make_pair(height, true);
    }
    return make_pair(height, false);
}

int main(void) {
    leaf* tree = buildTree();
    showTree(tree);
    cout << "Height: " << height(tree) << endl;
    cout << "Diameter: " << diameter(tree) << endl;
    cout << "Optimised diameter: " << optDiameter(tree).diameter << endl;
    cout << "Is height balanced? : " << isHeightBalanced(tree).second << endl;

    return 0;
}
