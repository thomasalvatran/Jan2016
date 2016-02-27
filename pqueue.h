#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Person
{
     int m_age;
     string m_name;
public:
   Person(string name, int age) : m_name(name), m_age(age){}
   string getName() { return m_name; }
   int getAge() { return m_age; }
};

bool operator< (Person a, Person b)
{
    return a.getAge() > b.getAge();   //need for priority queue based on age to set priority
}
int main()
{
    priority_queue<Person> pq;    //it expected to overload assignment <

    pq.push(Person("one", 1));
    pq.push(Person("two", 2));
    pq.push(Person("four", 4));
    pq.push(Person("three",3));

    while ( !pq.empty() )
    {
        Person p = pq.top();
        cout << p.getName() << " " << p.getAge() << endl;
        pq.pop();
    }
//    cin.get();
}
