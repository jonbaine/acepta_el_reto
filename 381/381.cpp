#include <bits/stdc++.h>
 
// Recursive function to return gcd of a and b 
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

long long lcm (std::vector<long long>& vector) {
    if (vector.size() == 1)
        return vector[0];
    
    long long a = vector.back();
    vector.pop_back();
    long long b = vector.back();
    vector.pop_back();
    vector.push_back(lcm(a,b));
    return lcm(vector);
}

int main (int argc, char* argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (;;){
        int planets;
        int orbit;
        std::vector<long long> orbits;
        orbits.reserve(5);
        std::cin >> planets;

        if (!planets)
            break;
        
        while (planets--){
            std::cin >> orbit;
            orbits.push_back(orbit);
        }
        
        sort(orbits.begin(), orbits.end(), std::greater<int>()); 

        std::cout << lcm(orbits) << std::endl;

    }
}