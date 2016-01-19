// Binary Search Tree - Implemenation in C++
// Simple program to create a BST of integers and search an element in it
//https://www.youtube.com/watch?v=COZK7NATh4k&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=28
//mycodeschool
#include<iostream>
using namespace std;
//Definition of Node for Binary search tree
struct BstNode {
    int data;
    BstNode* left;
    BstNode* right;
};

// Function to create a new Node in heap
BstNode* GetNewNode(int data) {
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// To insert data in BST, returns address of root node
BstNode* Insert(BstNode** root,int data) {
    if(*root == NULL) { // empty tree
        *root = GetNewNode(data);
    }
    // if data to be inserted is lesser, insert in left subtree.
    else if(data <= (*root)->data) {
        (*root)->left = Insert(&(*root)->left, data);
    }
    // else, insert in right subtree.
    else {
        (*root)->right = Insert(&(*root)->right, data);
    }
    return *root;
}
//To search an element in BST, returns true if element is found
bool Search(BstNode* root,int data) {
    if(root == NULL) {
        return false;
    }
    else if(root->data == data) {
        return true;
    }
    else if(data <= root->data) {
        return Search(root->left,data);
    }
    else {
        return Search(root->right,data);
    }
}
void printout(BstNode * tree) {  //inorder = binary search tree (sorting order)
    if(tree->left)
        printout(tree->left);
    printf("%d ",tree->data);
    if(tree->right)
        printout(tree->right);
     //printf("\n");
}

void print_preorder(BstNode * tree)
{
    if (tree)
    {
        printf("%d ",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }
}

void print_inorder(BstNode * tree)  //also binary search tree (sorting order)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d ",tree->data);
        print_inorder(tree->right);
    }
}

void print_postorder(BstNode * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d ",tree->data);
    }
}


int main() {
    BstNode* root = NULL; // Creating an empty tree
    /*Code to test the logic*/
    Insert(&root,15);
    Insert(&root,10);
    Insert(&root,20);
    Insert(&root,25);
    Insert(&root,8);
    Insert(&root,12);
    printout(root);
    printf("\n preoder\n");
    print_preorder(root);
    printf("\n inorder\n");
    print_inorder(root);
    printf("\n postorder\n");
    print_postorder(root);
    printf("\n");
    // Ask user to enter a number.
    int number;
    cout<<"Enter number to be searched\n";
    cin>>number;
    //If number is found, print "FOUND"
    if(Search(root,number) == true)
        cout<<"Found\n";
    else
        cout<<"Not Found\n";
}
