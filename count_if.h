#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct IsMultiOf
{
    int m_i;
    IsMultiOf(int i) : m_i(i) {}
    bool operator()(int x)
    {
        return !( x % m_i);
    }
};
bool isEven(int x)
{
    return !(x % 2);
}

int main()
{
    int mult = 3;
    vector<int> v = { 1, 3, 4, 6, 7, 21 };
    size_t c = count_if(v.begin(), v.end(), IsMultiOf(3));
    size_t c1 = count_if(v.begin(), v.end(), isEven);
    size_t c2 = count_if(v.begin(), v.end(), [mult](int x){ return !( x % mult); });
    cout << c << " "<< c1  << " " << c2 << endl;
}
