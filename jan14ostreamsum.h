#include <iostream>
using namespace std;

class Three
{
    string *m_ob;
    int m_x, m_y, m_z;
public:
    Three(){}
    Three(string ob, int x, int y, int z): m_ob(new string(ob)), m_x(x), m_y(y), m_z(z) {}
    Three &operator+(Three &t)
    {
        Three th;
        th.m_ob = new string("Sum object");
        th.m_x = this->m_x + t.m_x;
        th.m_y = this->m_y + t.m_y;
        th.m_z = this->m_z + t.m_z;
        return th;
    }

    friend ostream &operator<< (ostream &stream, Three t)
    {
        stream << *t.m_ob <<": ",
        stream << t.m_x << ",";
        stream << t.m_y << ",";
        stream << t.m_z << "\n";
        return stream;
    }
};

int main()
{
    Three ob1("ob1", 1, 2, 3), ob2("ob2", 4, 5, 6), ob3("ob3", 7, 8, 9);
    cout << ob1 << ob2 << ob3 << endl;
    Three ob = ob1 + ob2 + ob3;
    int sum = 1 + 2 + 3;
    cout << ob << " " << sum << endl;
}
