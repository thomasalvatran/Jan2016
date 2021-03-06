// thread.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"



//int _tmain(int argc, _TCHAR* argv[])
//{
//	return 0;
//}

//Bartosz Milewski youtube C++ Concurrency Part 1
//home/tovantran/Ctest/k_r/thread/thread.cpp --> 2015-11-10 by ./.tv  owner: tovantran

//Bartosz Milewski youtube C++ Concurrency Part 2
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm> //for_each
#include <unistd.h> //sleep(1)
//#include <Windows.h>

//void threadFunction(std::thread &th)
//{
//		th.join();
//}

int main()
{
    std::vector<std::thread> workers;
    for (int i = 0; i < 10; i++)
    {
        workers.push_back(std::thread([i]()  //construct a thread called ctor
        {
            std::cout << "Hello From Thread ! Index " << i <<  "\n"; //Worker thread define inline  / parallelism then join (task/thread base program)
                                                                //non determinism in concurrency program very clear from video
            std::cout << std::this_thread::get_id() << "\n";
        }));

    }
    sleep(2);
    std::cout << "Hello World From Main \n";
    //Sleep(2000);
    std::for_each(workers.begin(), workers.end(), [](std::thread &th)  //lambda replace threadFunction
    {
        th.join();
    });
    return 0;
}

