//How to create a dynamic array of an Abstract class?
//http://stackoverflow.com/questions/31410858/adding-elements-to-stdvector-of-an-abstract-class
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Animal  //this ABC has pure virtual function class is called Interface same as Java.
{
public:
    string name;
    Animal(const string name) : name(name) { cout <<  "Base class Animal" << endl; }
    virtual string talk() = 0;
};

class Dog : public Animal
{
public:
    Dog(const string name) : Animal(name){}
    virtual string talk() { return "Bark"; }
};

class Cat: public Animal
{
public:
    Cat(const string name): Animal(name){}
    virtual string talk() { return "Meo"; }
};


int main()
{
    Dog dog("Tippy");
    cout << dog.talk() << endl;
    Cat cat("Missy");
    cout << cat.talk() << endl;
    Animal *animals[] =
    {

        new Cat("Missy"),
        new Dog("Lassie")
    };
//    for (int i = 0; i < 2 ; i++)
//    {
//        cout << animals[i]->name << '\t'<< animals[i]->talk() << endl;
//        delete ani[i]; //free memory
//    }
    for (auto a: animals)
    {
        cout << a->name << '\t'<< a->talk() << endl;
        delete a;
    }
    vector<unique_ptr<Animal>> a;  //Vector: dynamic array

    a.push_back(make_unique<Dog>("Dog"));  //smart pointer write
    a.push_back(make_unique<Cat>("Cat"));

    for (auto & e: a)                      //read
    {
        cout << e->name << '\t' << e->talk() << endl;
    }
    // no need to do anything here.  the vector will get rid of each unique_ptr and each unique_ptr will delete each pointer

    return 0;
}
