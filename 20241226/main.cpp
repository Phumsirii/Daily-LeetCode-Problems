#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> dp;

    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums, target, 0);
    }

    int recur(vector<int>& nums, int target, int idx) {
        if (idx == nums.size()) {
            return target == 0;
        }
        string key = to_string(idx) + "," + to_string(target);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }
        int add = recur(nums, target - nums[idx], idx + 1);
        int subtract = recur(nums, target + nums[idx], idx + 1);
        return dp[key] = add + subtract;
    }
};
