#include <bits/stdc++.h>

int calculateDigits (int target) {

    switch (target)
    {
    case 0 ... 9:
    {
        return target;
    }
        break;
    case 10 ... 99:{
        return 2 * (target-9)  + calculateDigits(9);
    }
        break;
    case 100 ... 999:{
        return 3 * (target-99) + calculateDigits(99);
    }
        break;
    case 1000 ... 9999:{
        return 4 * (target-999) + calculateDigits(999);
    }
        break;
    case 10000 ... 99999:{
        return 5 * (target-9999) + calculateDigits(9999);
    }
        break;
    case 100000 ... 999999:{
        return 6 * (target-99999) + calculateDigits(99999);
    }
        break;
    case 1000000 ... 9999999: {
        return 7* (target - 999999) + calculateDigits(999999);
    }
    break;
    }

    return -1;
}
int calculateIntervalDigits (int start, int end) {
    //Take care we calculate digits from the previous page.
    return calculateDigits(end) - calculateDigits(start-1);
}

int binarySearch(int start, int end, int pivotleft, int pivotright){
    int mid = (pivotleft + pivotright) / 2;

    if ( (pivotleft - pivotright) == 0)
        return std::max(start, mid-1);
    
    int first = calculateIntervalDigits(start, mid);
    int second = calculateIntervalDigits(mid+1, end);
        
    if (first == second)
        return mid;

    if ( first < second ){
        return binarySearch(start, end, mid+1, pivotright); 
    }
        
    if (first > second) {
        return binarySearch(start, end, pivotleft, mid-1);
    }
    return -1;
}

int main (int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (;;){
        int start, end;
        std::cin >> start;
        std::cin >> end;

        if (start == 0 && end == 0)
            break;

        // Since we can calculate the digit number on the fly we perform a binary search over that space.
        std::cout << binarySearch (start, end, start, end) <<std::endl;
    }
}