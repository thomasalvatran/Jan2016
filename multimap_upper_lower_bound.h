//multimap from cplusplus.com
#include <iostream>
#include <map>

int main()
{
    std::multimap<char, int> mymultimap;
    std::multimap<char, int>::iterator it, itlow, itup;
    mymultimap.insert(std::make_pair('a', 10));
    mymultimap.insert(std::make_pair('b', 121));
    mymultimap.insert(std::make_pair('c', 1001));
    mymultimap.insert(std::make_pair('c', 2002));
    mymultimap.insert(std::make_pair('d', 11011));
    mymultimap.insert(std::make_pair('e', 44));

    itlow = mymultimap.lower_bound('b');
    itup = mymultimap.upper_bound('d');

    for (it = itlow; it != itup; ++it)
        std::cout << it->first << " => " << it->second << std::endl;
}
