#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
    Node* parent;
    Node* left;
    Node* right;
    int value;
    Node(int v) {
        parent = NULL;
        left = NULL;
        right = NULL;
        value = v;
    }
    void del(){
        if (left != NULL)
            left->del();
        if (right != NULL)
            right->del();
        delete this;
    }
    Node* addChild(int v, int pos = 0) {
        bool add2Left;
        switch (pos) {
            case 0:
                if (left == NULL)
                    add2Left = true;
                else if (right == NULL)
                    add2Left = false;
                else
                    add2Left = true;
                break;
            case 1:
                add2Left = true;
                break;
            case 2:
                add2Left = false;
                break;
            default:
                break;
        }
        Node* newNode = new Node(v);
        newNode->parent = this;
        if (add2Left) {
            if (this->left != NULL)
                left->del();
            this->left = newNode;
        }
        else {
            if (this->right != NULL)
                right->del();
            this->right = newNode;
        }
        return newNode;
    }
};
class BinaryTree {
public:
    Node* root;
    BinaryTree();
    BinaryTree(Node* n){
        root = n;
    }
    void DFprintValue(Node* root) const {
        cout << root->value << " ";
        if (root->left != NULL)
            DFprintValue(root->left);
        if (root->right != NULL)
            DFprintValue(root->right);
    }
    void BFprintValue(Node* root) const {
        queue<Node*> visitOdr;
        visitOdr.push(root);
        while (!visitOdr.empty()) {
            Node* visiting = visitOdr.front();
            cout << visiting->value << " ";
            if (visiting->left != NULL)
                visitOdr.push(visiting->left);
            if (visiting->right != NULL)
                visitOdr.push(visiting->right);
            visitOdr.pop();
        }
    }
};

class BinarySearchTree {
public:
    Node* root;
    BinarySearchTree();
    BinarySearchTree(Node* n){
        root = n;
    }
    void DFprintValue(Node* root) const {
        cout << root->value << " ";
        if (root->left != NULL)
            DFprintValue(root->left);
        if (root->right != NULL)
            DFprintValue(root->right);
    }
    void BFprintValue(Node* root) const {
        queue<Node*> visitOdr;
        visitOdr.push(root);
        while (!visitOdr.empty()) {
            Node* visiting = visitOdr.front();
            cout << visiting->value << " ";
            if (visiting->left != NULL)
                visitOdr.push(visiting->left);
            if (visiting->right != NULL)
                visitOdr.push(visiting->right);
            visitOdr.pop();
        }
    }
    void insert(Node* root, int v) {
        bool toLeft;
        toLeft = root->value > v ? true : false;
        if (toLeft) {
            if (root->left != NULL)
                insert(root->left, v);
            else
                root->addChild(v, 1);
        }
        else {
            if (root->right != NULL)
                insert(root->right, v);
            else
                root->addChild(v, 2);
        }
    }
    Node* getMin(Node* root) const {
        if (root->left == NULL)
            return root;
        else
            return getMin(root->left);
    }
    Node* getMax(Node* root) const {
        if (root->right == NULL)
            return root;
        else
            return getMax(root->right);
    }
    int delMin(Node* root) {
        Node* toDelete = getMin(root);
        int ret = toDelete->value;
        toDelete->parent->left = NULL;
        toDelete->del();
        return ret;
    }
    int delMax(Node* root) {
        Node* toDelete = getMax(root);
        int ret = toDelete->value;
        toDelete->parent->right = NULL;
        toDelete->del();
        return ret;
    }
    int remove(Node* root) {
        int ret = root->value;
        root->value = delMax(root->left);
        return ret;
    }
};

int main() {
    int arr[10] = {8,6,9,12,2,7,11,15,20,14};
    Node* n = new Node(10);
    BinarySearchTree bst(n);
    for (int i = 0; i < 10; ++i)
        bst.insert(bst.root, arr[i]);
    bst.BFprintValue(bst.root);
    cout << bst.remove(bst.root) << endl;
    bst.BFprintValue(bst.root);
}
