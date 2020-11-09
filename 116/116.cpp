#include <iostream>

int main (int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  int times;
  std::cin >> times;
  for (; times>0; times--)
    std::cout<<"Hola mundo."<<std::endl;
}
