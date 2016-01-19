//http://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html
//http://www.codeproject.com/Articles/15351/Implementing-a-simple-smart-pointer-in-c
//: C03:PointerToFunction.cpp  ref. FunctionPointer1.cpp
#include <iostream>
using namespace std;

template <typename T>
int doMath(int x, int y, T func)
{
    cout << "Function pointer " << endl;
    return func(x, y);
}
class MathComputer
{
    int m_x;
public:
    MathComputer(int i): m_x(i) { }
    virtual int computerResult(int x, int y) = 0;
    int operator()(int x, int y) { return x * y; }
    int add(){}
};

class MathComputerDerived : public MathComputer
{
public:
    int m_i;
    MathComputerDerived(int i, int j): MathComputer(i){ m_i = j; }
    int computerResult(int x, int y)
      {
          cout << "Override Virtual Function at run time" << endl;
          return (x + y);
      }
    int add(int x, int y)
     {
     cout << "Overload function in base class at compile time" << endl;
     return x + y;
     }
};

int sum( int i, int j)
{
    return (i + j);
}
int add(int(*funcptr)(int, int), int i, int j)
{
    return funcptr(i, j);
}

int main()
{
    int i = 1, j = 2;

    int (*fp)(int a, int b);
    fp = sum;
    cout << (*fp)(i, j) << endl; //Function pointer
    cout << sum(i, j) << endl;
    cout << add(fp, i, j) << endl;

    MathComputerDerived mc(1, 2);
    cout << mc.computerResult(1, 2) << endl; //virtual function
    MathComputer *m = &mc;
    cout << m->computerResult(11, 4) << endl;

    cout << mc.operator ()(9, 2) << endl;  //Functor here is a function but it can be smart pointer
    cout << mc(10, 3) << endl;
}
