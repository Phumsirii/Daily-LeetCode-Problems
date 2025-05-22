#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int n = nums.size();
        priority_queue<int> topRight;
        vector<int> delta(n + 1,0);
        int oper = 0;
        for(int i = 0, j = 0; i < n; ++i){
            oper += delta[i];
            while(j < queries.size() && queries[j][0] == i){
                topRight.push(queries[j][1]);
                ++j;
            }
            while(oper < nums[i] && !topRight.empty() && topRight.top() >= i){
                ++oper;
                --delta[topRight.top() + 1];
                topRight.pop();
            }
            if (oper < nums[i]) {
                return -1;
            }
        }
        return topRight.size();
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 3}};
    cout << sol.maxRemoval(nums, queries) << endl; // Output: 2
    return 0;
}