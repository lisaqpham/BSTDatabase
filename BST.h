#include "TreeNode.h"
#include <cstddef>
#include <iostream>

using namespace std;

template <typename T>
class BST {
  private:
    TreeNode *root;

  public:
    BST();
    ~BST();

    bool search(T value);
    void insert(T value);

    //delete placeholder
    bool deleteNode(T key);

    //helper functions
    bool isEmpty();
    TreeNode* getMin();
    TreeNode* getMax();
    void printTree();
    void recPrint(TreeNode<T> *node);
    TreeNode* getSuccessor(TreeNode<T> *d);
};

template <typename T>
BST<T>::BST() {
  root = NULL; //empty tree
}

template <typename T>
BST<T>::~BST() {
  // research
}

template <typename T>
void BST<T>::recPrint(TreeNode<T> *node) {
  if (node == NULL)
    return;

  recPrint(node->left);
  cout << node -> key << endl;
  recPrint(node->right);
}

template <typename T>
void BST<T>::printTree() {
  recPrint(root);
}

template <typename T>
TreeNode* BST<T>::getMax() {
  TreeNode *current = root;

  if(root == NULL)
    return NULL;

  while(current->right != NULL) {
    current = current->right; //keep going down the right side of the tree
  }

  return current;
}

template <typename T>
void BST<T>::insert(T value) {
  //check if value exists in tree before proceeding
  TreeNode *node = new TreeNode(value);

  if(root == NULL) //empty tree
    root = node;
  else {
    //the tree is not empty, so let's find the insertion point
    TreeNode *current = root;
    TreeNode *parent = NULL;

    while (true) {
      parent = current;

      if (value < current -> key) {
        //we go left
        current = current -> left;
        if (current == NULL) {
          parent -> left = node;
          break;
        }
      } else {
        //we go right
        current = current -> right;
        if (current == NULL) {
          parent -> right = node;
          break;
        }
      }
    }
  }
}

template <typename T>
bool BST<T>::search(T value) {
  if (root == NULL)
    return false;

    //if we make it this far then we know the tree is not empty
    //lets attempt to find the key
    TreeNode<T> *current = root;
    while (current -> key != value) {
      if (value < current -> key)
        current = current -> left;
      else
        current = current -> right;
      if (current == NULL) //value not in tree
        return false;
    }

    return true;
}

template <typename T>
bool BST<T>::deleteNode(T value) {
  if (root == NULL)
    return false;

  TreeNode<T> *parent = root;
  TreeNode<T> *current = root;
  bool isLeft = true;

  //let's attempt to find the node to be deleted
  while (current -> key != value) {
    parent = current;
    if(value < current -> key) {
      //go left
      isLeft = true;
      current = current -> left;
    } else {
      // we go right
      isLeft = false;
      current = current -> right;
    }
    if (current == NULL) //value doesn't exist
      return false;
  }
  //if we make it here, then we found the node to be deleted

  if (current -> left == NULL && current -> right == NULL) {
    //then node is a leaf, no children
    if (current == root)
      root = NULL;
    else if (isLeft) {
      parent -> left = NULL;
    } else {
      parent -> right = NULL;
    }
  } else if (current -> right == NULL) { //node to be deleted has one child, it's a left (no right child)
    if (current == root) {
      root = current -> left;
    } else if (isLeft) {
      parent -> left = current -> left;
    } else {
      parent -> right = current -> left;
    }
  } else if (current -> left == NULL) { //node to be deleted has one child, it's a right (no left child)
    if (current == root) {
      root = current -> right;
    } else if (isLeft) {
      parent -> left = current -> right;
    } else {
      parent -> right = current -> right;
    }
  } else {
    // the node to be deleted has two children
    // at this state the cortisol increases exponentially

    TreeNode<T> *successor = getSuccessor(current);

    if (current == root)
      root = successor;
    else if (isLeft) {
      parent -> left = successor;
    } else {
      parent -> right = successor;
    }
    successor -> left = current -> left;
  }
  return true;
}

template <typename T>
TreeNode* BST<T>::getSuccessor(TreeNode *d) { //d is the node to be deleted
  TreeNode<T> *current = d->right;
  TreeNode<T> *sp = d; //successors parent
  TreeNode<T> *successor = d;

  while (current != NULL) {
    sp = successor;
    successor = current;
    current = current -> left;
  }
  //we made it here, that means we found our successor
  if (successor != d -> right) {
    sp -> left = successor -> right;
    successor -> right = d -> right;
  }
  return successor;
}
