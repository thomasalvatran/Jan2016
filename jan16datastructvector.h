#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 5;
//vector<int> v {5};
//vector<int> v {1, 2, 3, 4, 5};
vector<int> v;
int rear = 0, front = 0;
bool isEmpty()
{
    return ( rear == 0 && front == 0);
}
bool isFull()
{
    return (rear + 1) % SIZE == front;
}

void enqueue(int i)
{
    if(isFull())
    {
        cout <<"Queue is full for " << i << endl;
        return;
    }
    rear = (rear + 1) % SIZE;
    v[rear] = i;
}
void dequeue()
{
    if(isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    front = (front + 1) % SIZE;
}
void print()
{
    cout << "V = " << v.size() << endl;
    int count = (SIZE + rear -front) % SIZE + 1;
    for (int i = 0; i < count; i++)
    {
        int index = (front + i) % SIZE;
        cout << v[index] << "[" << index << "] ";
    }
    cout << '\n';
}

int main()
{
    enqueue(20);
    enqueue(21);
    enqueue(22);
    enqueue(23);
    enqueue(24);
    print();
}
