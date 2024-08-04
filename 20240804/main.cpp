#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> allSums;
        for(int start=0;start<n;++start){
            int currentSum=0;
            for(int stop=start;stop<n;++stop){
                currentSum+=nums[stop];
                allSums.push_back(currentSum);
            }
        }
        sort(allSums.begin(),allSums.end());
        int result=0;
        for(int i=left-1;i<right;++i){
            result+=allSums[i];
            result=result%(1000000007);
        }
        return result;
    }
};
int main(){
    Solution s;
    vector<int> nums={1,2,3,4};
    cout<<s.rangeSum(nums,4,1,5)<<endl;
    cout<<s.rangeSum(nums,4,3,4)<<endl;
    cout<<s.rangeSum(nums,4,1,10)<<endl;
}