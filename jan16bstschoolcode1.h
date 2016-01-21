#include <iostream>
using namespace std;

struct BstNode
{
    int data;
    BstNode *left;
    BstNode *right;
};

BstNode* createNewNode(int data)
{
    BstNode *newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

BstNode* insert(BstNode *root, int data)
{
    if (root == NULL)
        root = createNewNode(data);
    else if( data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right,data);
    return root;
}

bool search(BstNode *root, int data)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
        return true;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

void print(BstNode *root)
{
    if(root)
    {
        print(root->left);
        printf("%d ", root->data);
        print(root->right);
    }
}

int factorial(int n)
{
    if (n > 1)
       return  n * factorial(n - 1);
}

int main()
{
    BstNode *root = NULL;
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 25);
    print(root);
    cout << factorial(4) << endl;
}
