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

int descendantSum(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }

    int ls = descendantSum(root->left);
    int rs = descendantSum(root->right);

    int temp = root->data;

    root->data = ls + rs;
    return root->data + temp;
}

int main(void) {

    Node* root = levelOrderBuild();

    levelOrderPrint(root);

    // HDPair p = optDiameter(root);
    int sum = descendantSum(root);
    cout << "Descendant Sum: " << sum << endl;
    // cout << "optDiameter and height: " << p.diameter << ", " << p.height << endl;

    return 0;
}
