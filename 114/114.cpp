#include <iostream>

int main (int argc, char* argv[]) {

  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  int times, number;
  std::cin >> times;
  for (; times>0; times--){
    std::cin >> number;
    if (number <= 1){
        std::cout << "1" <<std::endl;
    } else if (number == 2) {
        std::cout << "2" <<std::endl;
    } else if (number == 3) {
        std::cout << "6" <<std::endl;
    } else if (number == 4) {
        std::cout << "4" <<std::endl;
    } else {
        std::cout << "0" << std::endl;
    }
  }
}
