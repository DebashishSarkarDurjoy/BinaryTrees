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

pair<int, bool> checkBalance(Node* root) {
    if (root == NULL) {
        return make_pair(0, true);
    }

    pair<int, bool> pLeft = checkBalance(root->left);
    pair<int, bool> pRight = checkBalance(root->right);

    pair<int, bool> p;
    p.second = false;

    if (pLeft.second && pRight.second && ( abs(pRight.first - pLeft.first) <= 1) ) {
        p.second = true;
    }

    int currentHeight = max(pLeft.first, pRight.first) + 1;
    p.first = currentHeight;

    return p;

}

int main(void) {
    // Node* root = levelOrderBuild();

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



    pair<int, bool> p;
    p = checkBalance(root);
    if (p.second == true) {
        cout << "Height balanced" << endl;
    }
    else {
        cout << "Height not balanced" << endl;
    }

    return 0;
}
