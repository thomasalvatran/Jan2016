/***********Queue ADT using Array ***********/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 5;
int array[SIZE];
int rear = 0, front = 0;

bool isFull()
{
    return (rear + 1) % SIZE == front;
}

bool isEmpty()
{
    return (rear == 0 && front == 0);
}

void enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is full for data " << data << endl;
        return;
    }
    rear = (rear + 1) % SIZE;
    array[rear] = data;
}
void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty " << endl;
        return;
    }
    front = (front + 1) % SIZE;
}
void printArray()
{
    int count = (SIZE + rear -front) % SIZE + 1;
    for (int i = 1; i < count; i++)
    {
        int index = (front + i) % SIZE;
        cout << array[index] << "[" << index << "] ";
    }
    cout << "\n";
}

/***********Queue ADT using Linked List ***********/
struct Node
{
    int data;
    struct Node *next;
};
struct Node *rearLL = NULL, *frontLL = NULL;
void enqueueLinkedList(int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if (rearLL == NULL && frontLL == NULL)
    {
        rearLL = frontLL = temp;
        return;
    }
    rearLL->next = temp;
    rearLL = temp;
}

void dequeueLinkedList()
{
    if (frontLL == NULL)
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else if (frontLL == rearLL)
        frontLL = rearLL = NULL;
    else
        frontLL = frontLL->next;
}
void printLinkedList()
{
    Node *temp = frontLL;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}
/**** Queue ADT using Tree *********/
struct BstNode
{
    int data;
    struct BstNode *left = 0, *right = 0;
};
BstNode* insertNode(BstNode *root, int data);
BstNode* enqueueTree(BstNode *root, int data)
{
    root = insertNode(root, data);
    return root;
}

BstNode* dequeueMinTree(BstNode *root)
{
    if (root == NULL)
        return root;
    BstNode *temp = root;
    while (temp->left->left != NULL) //advanced twice
    {
        temp = temp->left;
    }
    temp->left = NULL;  //set to none cut link
    delete temp->left;
    return root;
}

BstNode* dequeueMaxTree(BstNode *root)
{
    if (root == NULL)
        return root;
    BstNode *temp = root;
    while (temp->right->right != NULL)
    {
        temp = temp->right;
    }
    temp->right = NULL; //set to none cut link
    delete temp->right;
    return root;
}


BstNode* createNode(int data)
{
    BstNode *temp = new BstNode;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

BstNode* insertNode(BstNode *root, int data)
{
   if (root == NULL)
       root = createNode(data);
   else if (data < root->data)
       root->left = insertNode(root->left, data);
   else
       root->right = insertNode(root->right, data);
   return root;
}

BstNode* findMinMaxNodeLeftOrRight(BstNode *root, int LorR)
{
    if(LorR)
    {
        while (root->right != NULL)
            root = root->right;
    } else {
        while (root->left != NULL)
            root = root->left;
    }
    return root;
}

BstNode* removeNode(BstNode *root, int data)
{
  if (root == NULL)
      return root;
  else if (data < root->data)
     root->left = removeNode(root->left, data);
  else if (data > root->data)
     root->right = removeNode(root->right, data);
  else
  {
      if (root->left == NULL && root->right == NULL)
      {
          delete root;
          root = NULL;
      }
      else if (root->left == NULL)
      {
          BstNode *temp = root;
          root = root->right;
          delete temp;
      }
      else if (root->right == NULL)
      {
          BstNode *temp = root;
          root = root->left;
          delete temp;
      }
      else
      {
          BstNode *temp = findMinMaxNodeLeftOrRight(root->right, 1);
          root->right = removeNode(root->right, temp->data);
      }
  }
  return root;
}

BstNode* deleteTree(BstNode *root)
{
    if (root)
    {
        deleteTree(root->left);
        deleteTree(root->right);
        free(root); //dangling address
        root = NULL; //reset address to NULL
    }
    return root;
}

void printTree(BstNode *root)
{
    if (root)
    {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}
vector<int> vec; //global
void treetoBST(BstNode *root)
{
    if (root)
    {
        treetoBST(root->left);
        vec.push_back(root->data); //push end vector
        treetoBST(root->right);
    }
}

BstNode* findMax(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty " << endl;
        return root;
    }
    int max = root->right->data;
    while (root->right != NULL)
    {
        root = root->right;
        if (root->data >= max)
            max = root->data;
    }
    return root;
}

BstNode* findMin(BstNode *root)
{
    if (root == NULL)
    {
        cout << "Empty tree" << endl;
        return root;
    }
    int min = root->left->data;
    while (root->left != NULL)
    {
        root = root->left;
        if (root->data <= min)
            min = root->data;
    }
    return root;
}

bool searchNode(BstNode* root, int data)
{
    if (root == NULL)
        return false;
    else if (data == root->data)
    {
//        cout << "Found at " << root->data <<" "<< root->left << " "<< root->right << endl;
        return true;
    }
    else if (data < root->data)
        return searchNode(root->left, data);
    else
        return searchNode(root->right, data);
}

int binsearch(int x, vector<int> v, int n)
{
    int low = 0, high = 0, mid = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if ( x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int factorial(int n)
{
    if (n > 1)
        return n * factorial(n - 1);
    else
        return n;
}

int fibonacci (int n)
{
    if (n > 2)
        return fibonacci(n - 1) + fibonacci(n - 2);
    else
        return n;
}

int main()
{
    cout << "Factorial(4) " << factorial(4) << endl;
    cout << "Fibonacci(5) " << fibonacci(5) << endl;
    cout << "Queue array" << endl;
    enqueue(2);
    enqueue(4);
    enqueue(5);
    printArray();
    dequeue();
    printArray();
    cout << "Queue linked list " << endl;
    enqueueLinkedList(22);
    enqueueLinkedList(23);
    enqueueLinkedList(24);
    printLinkedList();
    dequeueLinkedList();
    printLinkedList();
    cout << "Binary Search Tree " << endl;
    BstNode *root = NULL;
    root = insertNode(root, 111);
    root = insertNode(root, 110);
    root = insertNode(root, 112);
    printTree(root);
    printf("\n");
    root = removeNode(root, 112);
    printTree(root);
    printf("\n");
    root = insertNode(root, 115);
    root = insertNode(root, 116);
    root = insertNode(root, 108);
    printTree(root);
    printf("\n");
    root = dequeueMinTree(root);
    printTree(root);
    printf("\n");
    root = dequeueMaxTree(root);
    printTree(root);
    printf("\n");
    cout << "Find Max Root " << (findMax(root)->data) << endl;
    cout << "Find Min Root " << (findMin(root)->data) << endl;
    printf("\n");
    int data;
    cout << "Enter data to be searched then delete it " << endl;
    cin >> data;
    cout << (searchNode(root, data) ? "Found ": "Not found") << endl;
    removeNode(root, data);
    printTree(root);
    printf("\n");
    cout << "Enter data to be added into the BST " << endl;
    while (cin >> data && data != 0x1B)  //0x1B == 'Esc'
    {
        root = insertNode(root, data);
        treetoBST(root);

        for_each(vec.begin(), vec.end(), [](int i){
           printf("%i ", i);
        });
        printf("\n");
        cout << "Position new data: "<< (binsearch(data, vec, vec.size())) << endl;
        vec.clear(); //reset the vector to start over
    }

}
