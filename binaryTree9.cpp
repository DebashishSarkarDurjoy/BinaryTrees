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

int main(void) {
    leaf* root = buildTree();

    showTree(root);
    cout << "Height: " << height(root) << endl;
    levelOrderPrint(root);

    return 0;
}

