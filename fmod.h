#include <iostream>
#include <memory>
#include <cmath>
using namespace std;

template <typename T>
class Functor
{
public:
    T m_i;
    Functor(T i) : m_i(i){}
    void operator()(T x)
    {
        cout << (fmod(x, m_i) ? "Odd": "Even") << endl;
    }
};

int main()
{
    Functor<int> t(2);
    t.operator ()(22);
    Functor<float> t1(2.2);
    t1.operator ()(4.4);
}


