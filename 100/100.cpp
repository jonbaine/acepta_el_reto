#include <bits/stdc++.h>

#define KAPREKAR 6174

std::vector<int> digits;

std::tuple<int, int> orderDigits(int num) 
{   
    digits.clear();
    int retValue = 0, remaning = num;
    for(int i = 0; i< 4; i++){
        if (remaning == 0)
            digits.push_back(0);
        else {
            digits.push_back(remaning%10);
            remaning /=10;
        } 
    }

    std::sort(digits.begin(), digits.end());
    int a =0, b = 0;
    for (int i = 0; i < 4; i++)
        a = (a*10) + digits[i];
    for (int i =4; i >= 0 ; i--)
        b = (b*10) + digits[i];
    return std::tuple<int, int>(a, b);
}   

int kaprekar (int target, int deep = 1){
    std::tuple<int, int> ordered= orderDigits(target);
    int c = std::abs(std::get<0>(ordered)-std::get<1>(ordered));
    std::cout << deep << " " << std::get<0>(ordered) << " " << std::get<1>(ordered) << " " << c << std::endl;
    if (c == KAPREKAR)
        return deep;
    return kaprekar(c, ++deep);
}

int main (int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    digits.reserve(4);
    int times, target;
    std::cin >> times;

    for (; times>0; times--){
        std::cin >> target;
        if (target == KAPREKAR)
            std::cout << 0 <<std::endl;
        else if ((target % 1111) == 0 || target == 0) {
            std::cout << 8 << std::endl;
        }
        else {
            std::cout << kaprekar(target) <<std::endl;
        }
    } 
}