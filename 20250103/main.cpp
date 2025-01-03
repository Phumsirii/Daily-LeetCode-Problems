#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        vector<long> cumSum(n);
        cumSum[0] = nums[0];
        for(int i = 1; i < n; ++i) cumSum[i] = cumSum[i - 1] + nums[i];
        int result = 0;
        for(int i = 0; i < n - 1; ++i){
            if (cumSum[i] >= cumSum[n - 1] - cumSum[i]) ++result;
        }
        return result;
    }
};