
#include <bits/stdc++.h>

int main (int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int elements;
    std::cin >> elements;
    for (int i = 0; i < elements; i++) {
        int measures, left, center, right, peak = 0, valley = 0;
        std::cin>> measures;
        if (measures > 2){
            std::cin>> left;
            std::cin>> center;
            for (int a = 0; a < measures-2; a++) {
                std::cin>> right;
                if (left > center && center < right)
                    valley++;
                if(left < center && center > right)
                    peak++;
                
                left = center;
                center = right;
            }
        } else {
            int remove;
            for (int r = 0; r < measures; r++)
                std::cin >> remove;
        }
        std::cout<< peak << " " << valley <<std::endl;
    }
}