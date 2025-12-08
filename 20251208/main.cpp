#include <iostream>

using namespace std;

class Solution
{
public:
    int countTriples(int n)
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            ans += nCountTriples(i);
        }
        return ans;
    }

    int nCountTriples(int n)
    {
        int count = 0;
        for (int i = 1; i < n; ++i)
        {
            int a = i * i;
            int remainder = n * n - a;
            int b = sqrt(remainder);
            if (b * b == remainder)
                ++count;
        }
        return count;
    }
};