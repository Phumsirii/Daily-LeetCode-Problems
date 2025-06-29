#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end(), greater<int>());
        unordered_map<int, int> selected;
        vector<int> result;
        for (int i = 0; i < k; ++i)
        {
            selected[sorted_nums[i]]++;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (result.size() == k)
                return result;
            if (selected.count(nums[i]))
            {
                result.push_back(nums[i]);
                selected[nums[i]]--;
                if (selected[nums[i]] == 0)
                    selected.erase(nums[i]);
            }
        }
        return result;
    }
};