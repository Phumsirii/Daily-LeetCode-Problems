#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        unordered_map<int, int> countMap;
        for (int num : nums)
        {
            countMap[num]++;
        }
        int ans = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (countMap.count(nums[i] + 1))
            {
                ans = max(ans, countMap[nums[i]] + countMap[nums[i] + 1]);
            }
        }
        return ans;
    }
};