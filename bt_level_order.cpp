#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* build_tree() {
    int input;
    cin >> input;

    if (input == -1) return NULL;

    Node* node = new Node(input);
    node->left = build_tree();
    node->right = build_tree();

    return node;
}

void levelOrderPrint(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* f = q.front();
        q.pop();
        if (f == NULL) {
            cout << endl;
            if (q.empty()) return;
            else q.push(NULL);
            continue;
        }
        cout << f->data << " ";
        if (f->left != NULL) q.push(f->left);
        if (f->right != NULL) q.push(f->right);
    }

}

int main(void) {
    Node* root = build_tree();
    levelOrderPrint(root);
    return 0;
}
