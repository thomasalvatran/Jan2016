//home/tovantran/Ctest/Jan11TestReview.cpp --> 2016-01-16 by ./.tv  owner: tovantran
//AllWebLearning.pdf
//youtube BoQian rvalue and lvalue

#include <iostream>
#include <memory>
#include <vector>
using namespace std;

struct Test
{
    int age;
    string name;
    Test(int age, string name): age(age), name(name){}
};

int main()
{
  int i;
  double d;

  int& r = i;
  // int& r1 = 5;
  // Jan11TestReview.cpp:20:13: error: invalid initialization of non-const reference of type ‘int&’ from an rvalue of type ‘int’

  int& r1 = i; //OK
  double& s = d;

  i = 5;
  cout << "Value of i: " << i << endl;

  cout << "Value of i reference " << r << endl;

  d = 11.7;
  cout << "Value of i: " << d << endl;

  cout << "Value of i reference " << s << endl;

  Test t(11, "tom");
  auto &t1 = t; /* auto t1 = t */
  cout << t1.name << '\t' << t1.age << endl ;
  auto *t2 = &t;
  cout << t2->name << '\t' << t2->age << endl ;

  Test *p(new Test(100, "Alex"));
  auto &p1 = p;
  cout << p1->name << '\t' << p1->age << endl;

  vector<unique_ptr<Test>> a;  //this is pointer *a
  a.push_back(make_unique<Test>(12, "tom1"));
  a.push_back(make_unique<Test>(13, "tom2"));

  //cout << a[0] << endl;

  for (auto& e: a)
  {
    cout << e->name << endl;
  }
//  auto &t3 = 5; FAIL
//  const auto &t3 = 5; // OK
  auto &t3 = i;   //OK
}
