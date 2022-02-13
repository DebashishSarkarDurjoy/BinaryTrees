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

Node* levelOrderBuild() {
    int input;
    cin >> input;
    Node* root = new Node(input);

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1) {
            current->left = new Node(c1);
            q.push(current->left);
        }
        if (c2 != -1) {
            current->right = new Node(c2);
            q.push(current->right);
        }

    }
    return root;

}

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int height1 = height(root->left);
    int height2 = height(root->right);

    return 1 + max(height1, height2);
}

int diameter(Node* root) {
    if (root == NULL) return 0;

    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D1, D2));
}

int main(void) {
    Node* root = levelOrderBuild();

    levelOrderPrint(root);

    cout << "Diameter: " << diameter(root) << endl;

    return 0;
}
