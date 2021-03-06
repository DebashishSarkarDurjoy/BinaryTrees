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

int nodesAtK(Node* root, Node* target, int k) {
    //base case
    if (root == NULL) {
        return -1;
    }

    //reached the target node
    if (root == target) {
        NodesAtKLevel(root, k);
        return 0;
    }

    //other case
    int DL = nodesAtK(root->left, target, k);
    if (DL != -1) {
        // 2 cases
        // print the current node
        if (DL + 1 == k) {
            cout << root->data << " ";
        }
        else {
            NodesAtKLevel(root->right, k-2-DL);
        }
        return 1 + DL;
    }

    int DR = nodesAtK(root->right, target, k);
    if (DR != -1) {
        // 2 cases
        // print the current node
        if (DR + 1 == k) {
            cout << root->data << " ";
        }
        else {
            NodesAtKLevel(root->left, k-2-DR);
        }
        return 1 + DR;
    }

    return -1;
}



int main(void) {

    Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->right = new Node(6);
	root->left->right->left = new Node(7);
	root->left->right->right = new Node(8);
	root->left->right->right->left = new Node(9);
	root->left->right->right->right = new Node(10);

    levelOrderPrint(root);

    nodesAtK(root, root->left->right, 2);
    cout << endl;

    return 0;
}
