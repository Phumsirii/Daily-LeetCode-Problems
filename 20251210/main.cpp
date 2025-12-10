#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPermutations(vector<int> &complexity)
    {
        const int MOD = 1e9 + 7;
        int n = complexity.size();
        for (int i = 1; i < n; ++i)
        {
            if (complexity[i] <= complexity[0])
                return 0;
        }
        int ans = 1;
        for (int i = 1; i < n; ++i)
            ans = (ans * 1LL * i) % MOD;
        return ans;
    }
};