#include<iostream>

int main (int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    uint number;
    std::cin >> number;
    uint target;

    for (int i=0; i < number; i++){
        std::cin >> target;
        uint five_divisors = target / 5;
        uint zeros = 0;
        /*
            We have to calculate the number of 5 divisors, but consider that 
            25 has 2 times 5, 125 3 times 5....
        */
        while (five_divisors > 0){
            zeros += five_divisors;
            five_divisors /= 5;
        }
        std::cout << zeros << std::endl;
    }
}
