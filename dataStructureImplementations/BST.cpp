#include<cstdio>
#include<iostream>

using namespace std;

typedef struct NODE {
  int data;
  struct NODE* left;
  struct NODE* right;
} Node;

Node* createNode(int data) {
  Node* n = new Node();
  n->data = data;
  n->left = nullptr;
  n->right = nullptr;

  return n;
}

Node* insertNode(Node* root, int data) {
  if (root == nullptr) return createNode(data);

  if (data < root->data) {
    root->left = insertNode(root->left, data);
  }

  else if (data > root->data) {
    root->right = insertNode(root->right, data);
  }

  return root;
}

Node* searchNode(Node* root, int data) {
  if (root == nullptr) return root;

  if (root->data == data) return root;

  else if (root->data > data) return searchNode(root->left, data);

  else return searchNode(root->right, data);
}

void traverse(Node* root) {
  if (root == nullptr) return;

  if (root->left != nullptr) traverse(root->left);
  cout << root->data << " ";
  if (root->right != nullptr) traverse(root->right);
}

Node* minValueNode(Node* root) {
  if (root == nullptr || root->left == nullptr) return root;

  return minValueNode(root->left);
}

Node* deleteNode(Node* root, int data) {
  if (root == nullptr) return root;

  else if (data > root->data) root->right = deleteNode(root->right, data);
  else if (data < root->data) root->left = deleteNode(root->left, data);

  //Found the node to delete
  else {
    //Only one child or none
    if (root->right == nullptr) {
      Node* temp = root->left;
      delete root;
      return temp;
    }
    else if (root->left == nullptr) {
      Node* temp = root->right;
      delete root;
      return temp;
    }
    else {
      //2 Childs

      Node* scsr = minValueNode(root->right);
      root->data = scsr->data;
      root->right = deleteNode(root->right, scsr->data);
    }
  }
  return root;
}

int main() {
  Node* root = nullptr;
  // create a BST
  root = insertNode(root, 50);
  root = insertNode(root, 30);
  root = insertNode(root, 20);
  root = insertNode(root, 40);
  root = insertNode(root, 70);
  root = insertNode(root, 60);
  root = insertNode(root, 80);

  // Print the inorder traversal of a BST
  cout << "Inorder traversal of the given Binary Search "
    "Tree is: ";
  traverse(root);
  cout << endl;

  // delete a node in BST
  root = deleteNode(root, 20);
  cout << "After deletion of 20: ";
  traverse(root);
  cout << endl;

  // Insert a node in BST
  root = insertNode(root, 25);
  cout << "After insertion of 25: ";
  traverse(root);
  cout << endl;

  // Search a key in BST
  Node* found = searchNode(root, 25);

  // check if the key is found or not
  if (found != nullptr) {
    cout << "Node 25 found in the BST." << endl;
  }
  else {
    cout << "Node 25 not found in the BST." << endl;
  }

  return 0;

}