#include <iostream>
#include <queue>
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

void levelOrderPrint(leaf* node) {
    queue<leaf*> q;
    q.push(node);
    q.push(NULL);

    while(!q.empty()) {
        leaf* front = q.front();

        if (front == NULL) {
            cout << endl;
            q.pop();

            if (!q.empty()) q.push(NULL);
        }

        else {
            q.pop();

            cout << front->data << " ";

            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
    }

    return ;
}

pair<int, bool> isHeightBalanced(leaf* node) {
    pair<int, bool> p;
    if (node == NULL) {
        p.first = 0;
        p.second = true;
        return p;
    }

    pair<int, bool> Left = isHeightBalanced(node->left);
    pair<int, bool> Right = isHeightBalanced(node->right);

    p.first = max(Left.first, Right.first) + 1;
    if (abs(Left.first - Right.first) <= 1 && Left.second && Right.second) {
        p.second = true;
        return p;
    }

    p.second = false;
    return p;
}

int main(void) {
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
    cout << "\n" << "Height: " << height(root) << endl;
    cout << "Optimised Diameter: " << optDiameter(root).second << endl;
    levelOrderPrint(root);
    cout << "\n" << "Is height balanced: " << isHeightBalanced(root).second << endl;

    return 0;
}
