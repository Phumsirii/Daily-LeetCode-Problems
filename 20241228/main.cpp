#include <iostream>
#include <vector>

using namespace std;

// SSS is currently the best approach I could imagine now
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cumSum(n);
        cumSum[0] = nums[0];
        for(int i = 1; i < n; ++i) cumSum[i] = cumSum[i - 1] + nums[i];
        vector<int> result(3);
        vector<int> sumResult(n - k + 1);
        for(int i = 0; i < n - k + 1; ++i) sumResult[i] = cumSum[i + k - 1] - cumSum[i] + nums[i];
        vector<int> bestTail(n - k + 1,0);
        bestTail[n - k] = sumResult[n - k];
        for(int i = n - k - 1; i >= 0; --i) bestTail[i] = max(bestTail[i + 1],sumResult[i]);
        int best = 0;
        for(int i = 0; i < n - 3 * k + 1; ++i){
            if (3 * bestTail[i] <= best) break;
            for(int j = i + k; j < n - 2 * k + 1; ++j){
                if (sumResult[i] + 2 * bestTail[j] <= best) break;
                for(int l = j + k; l < n - k + 1; ++l){
                    if (sumResult[i] + sumResult[j] + bestTail[l] <= best) break;
                    if (sumResult[i] + sumResult[j] + sumResult[l] > best){
                        best = sumResult[i] + sumResult[j] + sumResult[l];
                        result = {i, j, l};
                    }
                }
            }
        }
        return result;
    }
};