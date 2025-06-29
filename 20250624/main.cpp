#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int n = nums.size();
        vector<bool> isInResult(n, false);
        int current = 0;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == key)
            {
                current = max(current, i - k);
                for (int j = current; j <= min(n - 1, i + k); ++j)
                {
                    isInResult[j] = true;
                }
                current = i + k + 1;
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i)
        {
            if (isInResult[i])
            {
                result.push_back(i);
            }
        }
        return result;
    }
};