#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &nums, int diff)
    {
        int count = 0;
        int n = nums.size();
        int index = 0;
        while (index < n - 1)
        {
            if (nums[index + 1] - nums[index] <= diff)
            {
                ++count;
                ++index;
            }
            ++index;
        }
        return count;
    }

    int minimizeMax(vector<int> &nums, int p)
    {
        if (p == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n - 1] - nums[0];
        while (left < right)
        {
            int mid = (left + right) / 2;
            if (countPairs(nums, mid) >= p)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};