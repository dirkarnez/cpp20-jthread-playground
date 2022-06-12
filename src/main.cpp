#include <iostream>
#include <thread>
#include <chrono>
 
void foo()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(3));
}
 
void bar()
{
    // simulate expensive operation
    std::this_thread::sleep_for(std::chrono::seconds(1));
}


int main(void) {
  unsigned int n = std::jthread::hardware_concurrency();
  std::cout << n << " concurrent threads are supported.\n";

  std::cout << "starting first helper...\n";
  std::jthread helper1(foo);

  std::cout << "starting second helper...\n";
  std::jthread helper2(bar);

  std::cout << "waiting for helpers to finish..." << std::endl;
  helper1.join();
  helper2.join();

  std::cout << "done!\n";
  
  std::cin.get();

  return 0;
}