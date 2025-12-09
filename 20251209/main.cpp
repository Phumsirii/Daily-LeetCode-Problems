#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> totalCounts;
        unordered_map<int, int> leftCounts;
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ++totalCounts[nums[i]];
        }

        for (int i = 0; i < n; ++i)
        {
            if (leftCounts.count(nums[i] * 2))
            {
                int leftCount = leftCounts[nums[i] * 2];
                ++leftCounts[nums[i]];
                int rightCount = totalCounts[nums[i] * 2] - leftCounts[nums[i] * 2];
                ans = (ans + (leftCount * 1LL * rightCount % MOD)) % MOD;
            }
            else
                ++leftCounts[nums[i]];
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 0, 0};
    cout << s.specialTriplets(nums) << endl;
}