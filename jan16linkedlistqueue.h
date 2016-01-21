//linkedlist queue
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

void enqueue(int i)
{
    struct Node *temp = (struct Node *) malloc (sizeof(struct Node));
    temp->data = i;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue()
{
    struct Node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    if (front == rear)
        front = rear = NULL;
    else
        front = front->next;
    free(temp);
}

void print()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d[%d] ", temp->data, temp);
        temp = temp->next;
    }
    printf("\n");
}

bool search(int data)
{
   struct Node *temp = front;
   while (temp != NULL)
   {
       if (temp->data == data)
           return true;
       temp = temp->next;
   }
   return false;
}


int main()
{
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    print();
    enqueue(7);
    enqueue(9);
    enqueue(12);
    print();
    int number;
    cout << "Enter number to search\n";
    cin >> number;
    cout << (search(number) == true ? "Found" : "Not Found") << endl;
}
