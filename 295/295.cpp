#include <iostream>
#include <list>
#include <utility>

int K = 31543;
long long int elevame (long long int a, int b){
  if (b == 0) return 1;
  /*
  * Exponentiation by squaring
  */
  if ( (b % 2) == 0){
    long long int resultn_2 = elevame(a, b/2);
    return ((resultn_2 % K ) * (resultn_2 % K)) % K;
  }else {
    return ((a % K) * (elevame(a, b-1) % K)) % K;
  }
}

int main (int argc, char* argv[]) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  std::list<std::pair<int, int>> elements;
  for (;;){
    int a; 
    int b;  
    std::cin >> a;
    std::cin >> b;
    if (a == 0 && b == 0)
      break;
    elements.push_back({a, b});
  }

  for (std::pair<int, int> i : elements){
    int a = i.first;
    int b = i.second;

    std:: cout << elevame(a, b) << std::endl;
  
  }
}
