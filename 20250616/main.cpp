#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ans = 0, n = nums.size();
        vector<int> maxRight(n - 1);
        maxRight[n - 2] = nums[n - 1];
        for (int i = n - 3; i >= 0; --i)
        {
            maxRight[i] = max(maxRight[i + 1], nums[i + 1]);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            ans = max(ans, maxRight[i] - nums[i]);
        }
        return ans > 0 ? ans : -1;
    }
};