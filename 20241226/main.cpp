#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    // Custom hash function for pair<int, int>
    struct pair_hash {
        template <typename T1, typename T2>
        std::size_t operator()(const std::pair<T1, T2>& p) const {
            return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
        }
    };

    // index and currentSum -> the number of ways to reach the currentSum
    unordered_map<pair<int,int>, int, pair_hash> dp;

    int findTargetSumWays(vector<int>& nums, int target) {
        return recur(nums, target, 0);
    }

    int recur(vector<int>& nums, int currentSum, int idx) {
        if (idx == nums.size()) {
            return currentSum == 0;
        }
        if (dp.find({idx, currentSum}) != dp.end()) {
            return dp[{idx, currentSum}];
        }
        return dp[{idx, currentSum}] = recur(nums, currentSum - nums[idx], idx + 1) + recur(nums, currentSum + nums[idx], idx + 1);
    }
};
