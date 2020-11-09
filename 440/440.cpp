
#include <bits/stdc++.h>

int main (int argc, char* argv[]) {
  for (;;) {
    int max = INT_MIN;
    int min = INT_MAX;
    int currentSpeed, minSpeed, elements;
    int groups = 1, currentGroupSize = 1;

      std::cin >> elements;
      if (!elements){
	break;
      }

      std::cin >> minSpeed;
      for (int i=0; i < elements-1; i++){
	std::cin >> currentSpeed;
	if (minSpeed > currentSpeed){
	  groups++;
	  if (currentGroupSize > max)
	    max = currentGroupSize;
	  if (currentGroupSize < min)
	    min = currentGroupSize;
	  currentGroupSize = 1;
	  minSpeed = currentSpeed;
	} else {
	  currentGroupSize++;
	}

      }
    
    if (currentGroupSize > max)
      max = currentGroupSize;
    if (currentGroupSize < min)
      min = currentGroupSize;

    std::cout << groups << " " << min << " " << max <<std::endl;
    
  }
}
