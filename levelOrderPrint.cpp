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

Node* buildTree() {
    int input;
    cin >> input;

    if (input == -1) return NULL;

    Node* newNode = new Node(input);
    newNode->left = buildTree();
    newNode->right = buildTree();

    return newNode;
}

// Node* levelOrderBuild() {
//     int input;
//     cin >> input;
//     Node* root = new Node(input);
//
//     queue<Node*> q;
//     q.push(root);
//
//     while (!q.empty()) {
//         Node* current = q.front();
//         q.pop();
//
//         int c1, c2;
//         cin >> c1 >> c2;
//
//         if (c1 != -1) {
//             current->left = new Node(c1);
//             q.push(current->left);
//         }
//         if (c2 != -1) {
//             current->right = new Node(c2);
//             q.push(current->right);
//         }
// 
//     }
//     return root;
//
// }

void levelOrderPrint(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
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

int main(void) {
    Node* root = levelOrderBuild();
    levelOrderPrint(root);

    return 0;
}
