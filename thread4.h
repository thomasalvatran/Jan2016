#include <algorithm>
#include <thread>
#include <vector>
#include <iostream>

struct List
{
    struct Node
    {
        int m_x;
        Node *m_next;
        Node(int y) : m_x(y), m_next(nullptr){}
    };
    //List
    Node *m_head;
    List() : m_head(nullptr){}
    void insert(int x)
    {
        auto temp = new Node(x);
        temp->m_next = m_head;
        m_head = temp;
    }
    int count() const;
};

void thFun(List &list)
{
    for (int i = 0; i < 100; i++)
        list.insert(i);
}

int main()
{
    List list;
    std::vector<std::thread> workers;
    for (int i = 0; i < 10; ++i)
    {
        workers.push_back(std::thread(&thFun, std::ref(list)));
    }
    std::for_each(workers.begin(), workers.end(), [](std::thread &th)
    {
       th.join();
    });
    int total = list.count();
    std::cout << total << std::endl;
}

int List::count() const
{
    int n = 0;
    auto cur = m_head;
    while (cur != nullptr)
    {
        ++n;
        cur = cur->m_next;
    }
    return n;
}
