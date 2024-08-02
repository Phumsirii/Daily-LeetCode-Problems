#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int operate(int num,int target,vector<int> &nums){
        int maxInBox=0;
        for(int i=0;i<num;++i){
            if (nums[i]==target) ++maxInBox;
        }
        int n=nums.size();
        int currentBox=maxInBox;
        for(int i=1;i+num<n;++i){
            if (nums[i-1]==target) --currentBox;
            if (nums[i+num-1]==target) ++currentBox;
            maxInBox=max(currentBox,maxInBox);
        }
        return maxInBox;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int cntOnes=0;
        for(int &x:nums){
            if (x) ++cntOnes;
        }
        if (cntOnes==0 || cntOnes==n) return 0;
        return min(cntOnes-operate(cntOnes,1,nums),n-cntOnes-operate(n-cntOnes,0,nums));
    }
};
int main(){
    Solution s;
    vector<int> nums = {0,1,0,1,1,0,0};
    cout<<s.minSwaps(nums)<<endl;
}