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

void levelOrderPrint(leaf* root) {
    queue<leaf*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        leaf* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (q.empty()) return;
            else {
                q.push(NULL);
                continue;
            }
        }

        cout << front->data << " " ;
        if (front->left != NULL) q.push(front->left);
        if (front->right != NULL) q.push(front->right);
    }

    return;
}

pair<int, bool> heightBalance(leaf* node) {
    if (node == NULL) return {0, true};

    pair<int, bool> leftHeight = heightBalance(node->left);
    pair<int, bool> rightHeight = heightBalance(node->right);

    int newHeight = 1 + max(leftHeight.first, rightHeight.first);

    if (abs(leftHeight.first - rightHeight.first) <= 1 && leftHeight.second && rightHeight.second) {
        return {newHeight, true};
    }
    else return {newHeight, false};
}

int main(void) {
    leaf* root = buildTree();

    showTree(root);
    cout << "Height: " << height(root) << endl;
    levelOrderPrint(root);

    pair<int, bool> p = heightBalance(root);
    if (p.second) cout << "Height Balanced" << endl;
    else cout << "Height not balanced" << endl;

    return 0;
}

