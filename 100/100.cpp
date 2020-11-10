#include <bits/stdc++.h>

#define KAPREKAR 6174

int digits [4];
std::tuple<int, int> orderDigits(int num) 
{   
    int retValue = 0, remaning = num;
    for(int i = 0; i< 4; i++){
        if (remaning == 0)
            digits[i]=0;
        else {
            digits[i] = (remaning%10);
            remaning /=10;
        } 
    }

    //order digits
    for (int i = 0; i < 4; ++i){
        for (int j = i + 1; j < 4; ++j){
            if (digits[i] > digits[j]) {
                    int a =  digits[i];
                    digits[i] = digits[j];
                    digits[j] = a;
                }
            }
        }

    int a =0, b = 0;
    for (int i = 0; i < 4; i++)
        a = a*10 + digits[i];
    for (int i = 4; i >= 0; i--)
        b = b*10 + digits[i];
    return std::tuple<int, int>(a, b);
} 

int kaprekar (int target, int deep = 1){
    std::tuple<int, int> ordered= orderDigits(target);
    int c = std::abs(std::get<0>(ordered)-std::get<1>(ordered));
    if (c == KAPREKAR)
        return deep;
    return kaprekar(c, ++deep);
}

int main (int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
  
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