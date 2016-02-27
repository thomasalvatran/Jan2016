//Bartosz Milewski youtube C++ Concurrency Part 1
//home/tovantran/Ctest/k_r/thread/thread.cpp --> 2015-11-10 by ./.tv  owner: tovantran

#include <iostream>
#include <thread>

void threadFunction()
{
    std::cout << "Hello From Worker Thread ! \n"; //Worker thread
}

int main()
{
//	std::thread th(&threadFunction);
    std::thread th([](){
        std::cout << "Hello From Worker Thread ! \n"; //Worker thread
    });

    std::cout << "Hello World From Main \n";
  th.join();
  return 0;
}
