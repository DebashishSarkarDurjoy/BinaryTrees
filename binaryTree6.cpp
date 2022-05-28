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

void levelOrderPrint(leaf* root) {
    queue<leaf*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        leaf* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
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

pair<int, int> diameter (leaf* node) {
    pair<int, int> current;

    if (node == NULL) {
        current.first = 0;
        current.second = 0;
        return current;
    }

    pair<int, int> leftPair = diameter(node->left);
    pair<int, int> rightPair = diameter(node->right);

    current.first = max(leftPair.first, rightPair.first) + 1; // current height

    int D1 = leftPair.first + rightPair.first;
    int D2 = leftPair.second;
    int D3 = leftPair.second;

    current.second = max(D1, max(D2, D3));

    return current;
}

pair<int, bool> isHeightBalanced(leaf* node) {
    if (node == NULL) {
        return make_pair(0, true);
    }

    pair<int, bool> leftPair = isHeightBalanced(node->left);
    pair<int, bool> rightPair = isHeightBalanced(node->right);

    int currentHeight = max(leftPair.first, rightPair.first) + 1;

    if (abs(leftPair.first - rightPair.first) <= 1 && leftPair.second && rightPair.second) {
        return make_pair(currentHeight, true);
    }

    return make_pair(currentHeight, false);
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
	// root->left->right->right->left = new leaf(9);
	// root->left->right->right->right = new leaf(10);

    showTree(root);
    cout << endl;

    levelOrderPrint(root);

    pair<int, int> HD = diameter(root);
    cout << "height: " << HD.first << " Diameter: " << HD.second << endl;

    pair<int, bool> heightBalanceResult = isHeightBalanced(root);
    cout << "is height balanced: " << ( (heightBalanceResult.second == true) ? "True\n" : "False\n" );


    return 0;
}
