#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> opsCount(n + 1, 0);
        for (auto &query : queries)
        {
            int l = query[0], r = query[1];
            ++opsCount[l];
            --opsCount[r + 1];
        }
        vector<int> cumOpsCount(n, 0);
        int cumulativeOps = 0;
        for (int i = 0; i < n; ++i)
        {
            cumulativeOps += opsCount[i];
            cumOpsCount[i] = cumulativeOps;
        }
        for (int i = 0; i < n; ++i)
        {
            if (cumOpsCount[i] < nums[i])
            {
                return false;
            }
        }
        return true;
    }
};