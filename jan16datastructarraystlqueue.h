#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);





  //    for(auto a: q)
  //        cout << a.pop() << endl;
  int x;
  for (int i = 0; q.size(); i++) {
    cout << q.front() << endl;
    q.pop();
  }
  while (!q.empty())
   {
     std::cout << ' ' << q.front();
     q.pop();
   }
   std::cout << '\n';


   std::deque<int> mydeque;

    for (int i=1; i<=5; i++)
        mydeque.push_back(i);

    std::cout << "mydeque contains:";
    std::deque<int>::iterator it = mydeque.begin();

    while (it != mydeque.end())
      std::cout << ' ' << *it++;

    std::cout << '\n';


    std::cout << "mydeque contains1:";
    std::deque<int>::iterator it1 = mydeque.begin();

    while (it1 != mydeque.end())
      std::cout << ' ' << *it1++;

    std::cout << '\n';
}
