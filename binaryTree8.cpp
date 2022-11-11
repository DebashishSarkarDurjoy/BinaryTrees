#include <iostream>
#include <queue>
using namespace std;

class leaf {
public:
    int data;
    leaf* left;
    leaf* right;

    leaf(int i) {
        this->data = i;
        this->left = this->right = NULL;
    }
};

void levelOrderPrint(leaf* root) {
    queue<leaf*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        leaf* front = q.front();
        q.pop();
        if (front == NULL) {
            cout << endl;
            if (q.empty()) {
                return;
            }
            else {
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
}

int height(leaf* node) {
    // base case
    if (node == NULL) return 0;

    // recursive case
    int left = height(node->left);
    int right = height(node->right);

    return max(left, right) + 1;
}

void levelOrderPrint2(leaf* node) {
    queue<leaf*> q;
    q.push(node);
    q.push(NULL);

    while ( !q.empty() ) {
        leaf* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;
            if (q.empty()) return;
            else q.push(NULL);
        }
        else {
            cout << front->data << " ";
            if (front->left != NULL) q.push(front->left);
            if (front->right != NULL) q.push(front->right);
        }
    }
}

leaf* buildTree() {
    int input;
    cin >> input;

    if (input == -1) return NULL;

    leaf* node = new leaf(input);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

int main(void) {
    leaf* root = buildTree();
    levelOrderPrint2(root);

    cout << "Height: " << height(root) << endl;

    return 0;
}