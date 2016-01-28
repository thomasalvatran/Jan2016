/*********implement queue ADT using array  ***********/

#include <iostream>
using namespace std;

const int SIZE = 5;
int array[SIZE];
int front = 0, rear = 0;
bool isFull()
{
    return (rear + 1) % SIZE == front;
}
bool isEmpty()
{
    return (front == 0 && rear == 0);
}

void enqueue(int data)
{
    if(isFull())
    {
        cout << "Queue is full for " << data << endl;
        return;
    }
    rear = (rear + 1) % SIZE;   //****
    array[rear] = data;
}

void dequeue()
{
    if(isEmpty())
    {
        cout <<"Queue is empty" << endl;
        return;
    }
    front = (front + 1) % SIZE;  //****
}

void print()
{
    int count = (SIZE + rear -front ) % SIZE + 1;
    for (int i = 1; i < count; i++)
    {
        int index = (front + i) % SIZE;
        cout << array[index] << " [" << index << "]";
    }
    cout << endl;
}

//implement queue using linkedlist
struct Node
{
    int data;
    struct Node *next;
};
struct Node *rear1 = NULL, *front1 = NULL;

void enqueue1(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (rear1 == NULL && front1 == NULL)
    {
        rear1 = front1 = temp;
        return;
    }
    rear1->next = temp;   //linked list
    rear1 = temp;
}

void dequeue1()
{
//    struct Node *temp = front1;
    if (front1 == NULL)
    {
        printf("Queue is empty");
        return;
    }
    if (front1 == rear1)
        front1 = rear1 = NULL;
    else
        front1 = front1->next;
//    free(temp);
}

void print1()
{
    struct Node *temp = front1;
    while ( temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/********* implement queue using Tree **********/

struct BstNode
{
    int data;
    struct BstNode *left = 0, *right = 0;
};

BstNode* createNode(int data)
{
    BstNode *temp = new BstNode;
    temp->data = data;
    temp->left = temp->right = 0;
    return temp;
}

BstNode* insert(BstNode *root, int data)
{
    if (root == NULL)
      root = createNode(data);
    else if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

BstNode* deleteNode(BstNode *root, int data);
BstNode* removeNode(BstNode *root, int data)  //dequeue
{
    deleteNode(root, data);
}

void deletetrees(BstNode *root)  //delete all nodes in tree
{
    if (root)
    {
        deletetrees(root->left);
        deletetrees(root->right);
        free(root);
    }
}
/* 0 is left, 1 is right using to find Min or Max of right or left subtree */
BstNode* findMinMaxNodeLeftOrRight(BstNode *root, int LorR ) {
  if (!LorR) { /* 0 is left */
    while (root->left != NULL)
      root = root->left;
  } else {
    while (root->right != NULL)
      root = root->right;
  }
  return root;
}

BstNode* deleteNode(BstNode *root, int data) {  //delete a note in tree
  if (root == NULL)
    return root;
  else if (data < root->data)
    root->left = deleteNode(root->left, data);
  else if (data > root->data)
    root->right = deleteNode(root->right, data);
  else {
    // case 1: No child
    if (root->left == NULL && root->right == NULL) {
      delete root;  //still dangling address
      root = NULL;  //clear it
    }
    // case 2: One child
    else if (root->left == NULL) {
      BstNode *temp = root;
      root = root->right;
      delete temp;
    } else if (root->right == NULL) {
      BstNode *temp = root;
      root = root->left;
      delete temp;
    }
    // case 3: 2 children
    else {
      BstNode *temp = findMinMaxNodeLeftOrRight(root->right, 1);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;  //after delete root address is changed return root
}

int findMax(BstNode *root) {  /* Max is goes to right */
  if (root == NULL) {
    cout << "Error: Tree is empty\n";
    return -1;
  }
  int max = root->right->data; // skip root node
  while (root->right != NULL) {
    root = root->right;
    if (root->data >= max)
      max = root->data;
  }
  return max;
}

// In BST right side > root and left side < root
// Find a minimum goes left site of BST Binary Search Tree
int findMin(BstNode *root) {  /* Min goes to left */
  if (root == NULL) {
    cout << "Error: Tree is empty\n";
    return -1;
  }
  int min = root->left->data; // skip root node

  while (root->left != NULL) {
    root = root->left;
    if (root->data <= min)
      min = root->data;
  }
  return min;
}

int findMinRecur(BstNode *root) {
  if (root == NULL) {
    cout << "Eror: Tree is empty\n";
    return -1;
  } else if (root->left == NULL)
    return root->data;
  else
    return findMinRecur(root->left);
}


void print2(BstNode *root)
{
    if (root)
    {
      print2(root->left);
      printf("%d ", root->data);
      print2(root->right);
    }
}

bool search (BstNode *root, int data)
{
    if(root == NULL)
        return false;
    else if (data == root->data)
        return true;
    else if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

int factorial(int n)
{
    if (n > 0)
        return n * factorial(n - 1);
    else
        return 1;
}
int fibonacci(int n)
{
    if (n > 2)
        return fibonacci(n-1) + fibonacci(n-2);
    else
        return n;

}

int main()
{
    cout << "\nfactorial 4" << endl;
    cout << factorial(4) << endl;
    cout << "fibonacci 4 " << endl;
    cout << fibonacci(4) << endl;
    cout << "implement queue ADT using array" << endl;
    enqueue(2);
    enqueue(3);
    enqueue(4);
    print();
    dequeue();
    print();
    cout << "implement queue using linkedlist" << endl;
    enqueue1(22);
    enqueue1(23);
    enqueue1(24);
    enqueue1(25);

    print1();
    cout << "implement queue using tree" << endl;
    BstNode *root = NULL;
    root = insert(root, 100);
    root = insert(root, 101);
    root = insert(root, 102);
    root = insert(root, 90);
    root = insert(root, 95);
    print2(root);
    cout << "\n";
    cout << "findMin left tree Node = " << findMin(root) << endl;
    cout << "findMax Right tree Node = " << findMax(root) << endl;
    cout << "findMinRecursive Node = " << findMinRecur(root) << endl;

    cout << "\nsearch data in queue tree" << endl;
    int data;
    cout << "Enter data to search and delete that node" << endl;
    cin >> data;
    cout << (search(root, data) == true ? "Found " : "Not Found") << endl;
    deleteNode(root, data);
    print2(root);
//    deletetrees(root); //delete all nodes in tree
//    deleteNode(root, 101);
//    print2(root);

}
