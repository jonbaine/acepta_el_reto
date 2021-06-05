#include <bits/stdc++.h>

int main (int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int times, numberOfTries;
    std::string target, candidate;
    std::cin >> times;

    for (; times>0; times--){
        std::cin>> target >> numberOfTries;
        bool found = false;
        for (int i = 0; i < numberOfTries-1; i++){
            std::cin >> candidate;

            if ( !found && candidate == target )
            {
                std::cout << "FALSA" <<std::endl;
                found = true;
            }
        }
        std::cin >> candidate;
        if (!found){
            if (candidate == target && numberOfTries > 1){
                std::cout<< "VERDADERA" <<std::endl;
            } else {
                std::cout<< "FALSA" <<std::endl;
            }
        }
    }
}