/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw8/challenges/binary-tree-4/submissions/code/1322615691
 * Title: hw8_1
 * Abstract: provides a few functions for a binary search tree BST
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 10APR20
 */

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class Bst{
private:
    Node* root;
    Node* append(Node* node, int data);
    bool isBST(struct Node* node);
    int height(struct Node* node);
    void preOrder(Node* root);
    void postOrder(Node* root);
    void inOrder(Node* root);
    Node* deleteLastNode(Node* node, int level, bool &deleted);
    void levelOrder(Node* node, int level);

public:
    Bst();
    Bst(int data);
    bool append(int data);
    bool isBST();
    void preOrder();
    void levelOrder();
    void postOrder();
    int height();
    void deleteLastNode();
    void inOrder();
//    int isBST();
};

Bst::Bst()
{
    root = nullptr;
}

Bst::Bst(int data)
{
    root = nullptr;
    append(data);
}

Node* Bst::append(Node* node, int data){
    if(node == nullptr){
        node = new Node(data);
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
        node->parent = nullptr;
    }
    else if (node->data < data){
        node->right = append(node->right, data);
        node->right->parent = node;
    } else {
        node->left = append(node->left, data);
        node->left->parent = node;
    }
    return node;
}

bool Bst::append(int data){
    root = append(root, data);
    return true;
}

void Bst::levelOrder(){
    int h;
    h = height();
    for (int i = 0; i <= h; ++i) {
        levelOrder(root, i);
    }
}

void Bst::levelOrder(Node* node, int level) {
    if (node == nullptr){
        return;
    }
    else if (level == 0){
        cout << node->data << " ";
    } else {
        levelOrder(node->left, level-1);
        levelOrder(node->right, level-1);
    }
}

void Bst::deleteLastNode(){
    int h;
    h = height();
    bool deleted = false;
    root = deleteLastNode(root, h, deleted);
}
Node* Bst::deleteLastNode(Node* node, int level, bool &deleted){
    if (node == nullptr){
        return nullptr;
    }
    else if (level == 0){
        delete(node);
        deleted = true;
        return nullptr;
    }
    node->right = deleteLastNode(node->right, level-1, deleted);
    if (!deleted){
        node->left = deleteLastNode(node->left, level-1, deleted);
    } // my guess below. return node ?
    return node;
}

void Bst::inOrder(){
    inOrder(root);
}

void Bst::inOrder(Node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void Bst::preOrder(){
    preOrder(root);
}

void Bst::preOrder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void Bst::postOrder(){
    postOrder(root);
}

void Bst::postOrder(Node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

bool Bst::isBST(){
    return isBST(root);
}

bool Bst::isBST(struct Node* node)
{
    if (node == NULL)
        return true;

/* false if left is > than node */
    if (node->left != NULL && node->left->data > node->data)
        return false;

/* false if right is < than node */
    if (node->right != NULL && node->right->data < node->data)
        return false;

/* false if, recursively, the left or right is not a BST */
    if (!isBST(node->left) || !isBST(node->right))
        return false;

/* passing all that, it's a BST */
    return true;
}

int Bst::height(){
    return height(root);
}

int Bst::height(struct Node* node) {
    if (node==NULL) {
        return(-1);
    }
    else {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
        if (lDepth > rDepth) return(lDepth+1);
        else return(rDepth+1);
    }
}

int main()
{
    int input, counter, data;
    string into;
    cin >> input;
    Bst tree(input);
    cin >> counter;
    for (int i = 0; i < counter; ++i) {
        cin >> into;
        if (into == "append"){
            cin >> data;
            tree.append(data);
        }
        else if (into == "isBST"){
            cout << std::boolalpha << tree.isBST() << endl;
        }
        else if(into == "preOrder"){
            tree.preOrder();
            cout<<endl;
        }
        else if (into == "height"){
            cout << tree.height() << endl;
        }
        else if (into == "levelOrder"){
            tree.levelOrder();
            cout<<endl;
        }
        else if (into == "deleteLastNode"){
            tree.deleteLastNode();
        }
        else if(into == "postOrder"){
            tree.postOrder();
            cout<<endl;
        }
        else if (into == "inOrder"){
            tree.inOrder();
            cout<<endl;
        }
    }
    return 0;
}


