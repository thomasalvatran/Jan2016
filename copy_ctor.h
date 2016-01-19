//https://www.youtube.com/watch?v=2KvslbLHTUY
//youtube
#include <iostream>
using namespace std;

class Person
{
    string *m_name;
    int m_age;
public:
    Person(string name, int age): m_name(new string(name)), m_age(age){}
    Person(const Person& p): m_name(new string(*p.m_name)), m_age(p.m_age){}
    Person &operator=(const Person &p)
    {
        m_name = new string(*p.m_name); //*p.m_name == string p.m_name == address
        m_age = p.m_age;
    }

    void display()
    {
        cout << *m_name << " " << m_age << endl;
    }
    void setName(string name, int age)
    {
        *m_name = name;
        m_age = age;
    }
    ~Person()
    {
        delete this->m_name;
    }
};

int main()
{
    Person anil("anil", 20);
//    {
    Person tom("tom", 24);
    tom = anil;
    anil.display();
    tom.display();
//    } //end of scope both tom and anil will be destroy by destructor both same address
    anil.display();
    anil.setName("anil shetty", 100);
    anil.display();
    tom.display();

}
