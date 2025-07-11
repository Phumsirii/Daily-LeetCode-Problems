#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    char kthCharacter(int k)
    {
        int ans = 0;
        int t;
        while (k != 1)
        {
            t = static_cast<int>(log2(k));
            if (k == (1 << t))
            {
                --t;
            }
            k -= (1 << t);
            ans++;
        }
        return 'a' + ans;
    }
};