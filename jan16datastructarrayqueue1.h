// Array queue
#include <iostream>
using namespace std;

//#define MAX 5
// global
const int MAX = 5;
int array[MAX];  //actual only MAX - 1 are using because 1 empty
int rear = 0, front = 0;

bool isFull() { return (rear + 1) % MAX == front; } //(rear + 1) % MAX
bool isEmpty() { return (rear == 0 && front == 0); }

void enqueue(int i) {
  if (isFull())
  {
    cout << "Queue is full for " << i << endl;
    return;
  }
  rear = (rear + 1) % MAX;
  array[rear] = i;
}
void dequeue() {
  if (isEmpty())
    return;
  front = (front + 1) % MAX;
}
void print() {
  int count = (MAX + rear - front) % MAX + 1;  //start array[1]
  for (int i = 1; i < count; i++) {
    int index = (front + i) % MAX;
    cout << array[index] << " [" << index << "] ";
  }
  cout << "\n";
}

int main() {\
  print();
  enqueue(2);
  enqueue(3);
  print();

  dequeue();
  dequeue();
  print();

  enqueue(12);
  enqueue(13);
  enqueue(112);
  enqueue(113);

  enqueue(114);
//  enqueue(13);
  print();

}
