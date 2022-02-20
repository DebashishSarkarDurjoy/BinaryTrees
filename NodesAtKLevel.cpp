#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int i) {
        this->data = i;
        this->left = NULL;
        this->right = NULL;
    }

};

Node* buildTree() {

    int i;
    cin >> i;

    if(i == -1) return NULL;

    Node* node = new Node(i);
    node->left = buildTree();
    node->right = buildTree();

    return node;
}

Node* levelOrderBuild() {
    queue<Node*> q;
    int i;

    cin >> i;
    Node* root = new Node(i);
    q.push(root);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1) {
            front->left = new Node(c1);
            q.push(front->left);
        }
        if (c2 != -1) {
            front->right = new Node(c2);
            q.push(front->right);
        }

    }
    return root;
}

void levelOrderPrint(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* f = q.front();
        q.pop();

        if (f == NULL) {
            cout << endl;
            if (q.empty()) return;
            else {
                q.push(NULL);
                continue;
            }

        }

        cout << f->data << " ";
        if (f->left != NULL) {
            q.push(f->left);
        }
        if (f->right != NULL) {
            q.push(f->right);
        }

    }
}

void NodesAtKLevel(Node* root, int k) {
    if (root == NULL) {
        return ;
    }

    if (k == 0) {
        cout << root->data << " ";
        return ;
    }
    else {
        NodesAtKLevel(root->left, k-1);
        NodesAtKLevel(root->right, k-1);
    }

}

int main(void) {

    Node* root = levelOrderBuild();

    levelOrderPrint(root);

    NodesAtKLevel(root, 1);
    cout << endl;

    return 0;
}
