
#include <iostream>
#include <list>
using namespace std;

class Point
{
private:
    double m_dX, m_dY, m_dZ;

public:
    Point(double dX=0.0, double dY=0.0, double dZ=0.0)
    {
    m_dX = dX;
    m_dY = dY;
    m_dZ = dZ;
    }

    friend ostream& operator<< (ostream &out, Point &cPoint);

    double GetX() { return m_dX; }
    double GetY() { return m_dY; }
    double GetZ() { return m_dZ; }
};

ostream& operator<< (ostream &out, Point &cPoint)
{
    // Since operator<< is a friend of the Point class, we can access
    // Point's members directly.
    out << "(" << cPoint.m_dX << ", " <<
        cPoint.m_dY << ", " <<
        cPoint.m_dZ << ")";
    return out;
}
int main()
{
    Point cPoint1(2.0, 3.0, 4.0);
    Point cPoint2(6.0, 7.0, 8.0);

    using namespace std;
    cout << cPoint1 << " " << cPoint2 << endl;

    return 0;
}
