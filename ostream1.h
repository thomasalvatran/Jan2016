
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
    void print(ostream &output) const {  output << "testing...." << endl; }
    static ostream &ra(ostream &output)
    {
        output << "---------";
        return output;
    }

};

int main()
{
    list<int> l = {1, 2, 4};
    IntList *p = new IntList(10);
    p->data[0] = 1; //items
    cout << p->ra << endl;
//    ostream out = p->ra;
   // ostream s = "testing";
    //p->print(s);

    p->print(cout);
    cout << p << endl;

    ostream &out = cout;
    out <<"tesss" << endl;
    cout <<"wesss" << endl;


    delete p;
}
