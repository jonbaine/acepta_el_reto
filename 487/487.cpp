#include <bits/stdc++.h>

int MAX_DELAY = 3599;

int main (int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int times;
    long long hours, total;
    std::cin >> times;

    for (; times>0; times--){
        std::cin >> hours;
        total = hours + (hours / MAX_DELAY);
        if (hours % MAX_DELAY == 0)
            total--;
        std::cout << total <<std::endl;
    }
}
