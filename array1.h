//https://www.youtube.com/watch?v=2KvslbLHTUY
//youtube
#include <iostream>
#include <list>
using namespace std;

class IntList
{
public:
    int size;
    int *data;
    IntList(int sz) : size(sz), data(new int[sz]) {}
    ~IntList() { delete [] data; cout << "Dtor" << endl;}

};

int main()
{
    list<int> l = {1, 2, 4};
    IntList *p = new IntList(10);
    p->data[0] = 1; //items
    delete p;
}
