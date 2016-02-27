//http://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
#include <stdio.h>
#include <stdlib.h>
#include "adt1.h"


bool isBST(BstNode *root, int min, int max)
{
    if (root == 0)
        return true;
    if (root->data < min || root->data > max)
        return false;
    return isBST(root->left, min, root->data) &&
            isBST(root->right, root->data, max);
}

int main()
{ //create BST by hand
  struct BstNode *root = NULL;
//  struct BstNode *root = createNode(4); //set root a value 4
//  root->left        = createNode(2);
//  root->right       = createNode(5);
//  root->left->left  = createNode(1);
//  root->left->right = createNode(3);

  //Create BST using function
  root = insertNode(root, 4);  //set root a value 4
  insertNode(root, 2);
  insertNode(root, 5);
  insertNode(root, 1);
  insertNode(root, 13);

  int min = findMin(root)->data;
  int max = findMax(root)->data;
  printf(isBST(root, min, max) ? "BST\n" : "Not BST\n");

  cout << "Root tree is " << root->data << endl;
  printTree(root); //in order tree



}
