#include <iostream>

using namespace std;

class Solution
{
public:
    long long getDivisionCombination(int n)
    {
        if (n <= 0)
            return 0;
        return (long long)n * (n - 1) / 2;
    }
    long long distributeCandies(int n, int limit)
    {
        return getDivisionCombination(n + 2) - 3 * getDivisionCombination(n + 2 - limit - 1) + 3 * getDivisionCombination(n + 2 - 2 * limit - 2) - getDivisionCombination(n + 2 - 3 * limit - 3);
    }
};