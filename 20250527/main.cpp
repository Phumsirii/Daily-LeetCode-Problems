#include <iostream>

using namespace std;

class Solution
{
public:
    int differenceOfSums(int n, int m)
    {
        int maxFactor = n / m;
        int sumAll = (n * (n + 1)) / 2;
        int num2 = ((maxFactor * m + m) * maxFactor) / 2;
        int num1 = sumAll - num2;
        return num1 - num2;
    }
};