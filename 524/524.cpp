#include <bits/stdc++.h>

struct Price{
    int a;
    int b;
    int difference;
};

int main (int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    Price temp = {
        a : 0,
        b : 0,
        difference : 0,
    };
    int purchases, minc, mint, total;
    std::vector<Price> values;
    values.reserve(10000);


    for (;;) {
        values.clear();
        total = 0;
        std::cin >> purchases;
        if (purchases == 0)
            break;
        
        std::cin >> minc;
        std::cin >> mint;

        for (int i = 0; i < purchases; i++) {
            std::cin >> temp.a;
            values.push_back(temp);
        }
        for (int i = 0; i < purchases; i++) {
            std::cin >> values[i].b;
            values[i].difference = values[i].a - values[i].b;
        }
        std::sort(values.begin(), 
                values.end(),
                [](Price a, Price b) -> bool { return std::abs(a.difference) > std::abs(b.difference); }
                );

        for (int i = 0; i < purchases; i++){
            if((purchases - i) == minc){
                total += values[i].a;
                minc--;
                continue;
            }

            if((purchases -i ) == mint){
                total += values[i].b;
                mint--;
                continue;
            }

            if (values[i].difference < 0){
                total += values[i].a;
                minc--;
                continue;
            }

            if (values[i].difference > 0){
                total += values[i].b;
                mint--;
                continue; 
            } 

            //equal
            (minc > mint)? minc--:mint--;
            total += values[i].a;
            
        }
        std::cout<< total <<std::endl;
    }

}