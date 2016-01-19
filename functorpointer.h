//http://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html
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
public:
    virtual int computerResult(int x, int y) = 0;
    int operator()(int x, int y) { return x * y; }
};

class MathComputerDerived : public MathComputer
{
public:
    int computerResult(int x, int y)

    {
        cout << "Derived virtual function " << endl;
        return (x + y);
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
    cout << (*fp)(i, j) << endl;
    cout << sum(i, j) << endl;
    cout << add(fp, i, j) << endl;

    MathComputerDerived mc;
    cout << mc.computerResult(1, 2) << endl;
    MathComputer *m = &mc;
    cout << m->computerResult(11, 4) << endl;

    cout << mc.operator ()(9, 2) << endl;
    cout << mc(10, 3) << endl;
}
